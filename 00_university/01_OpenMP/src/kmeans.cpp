#include "../include/kmeans.h"

#include <cstdint>
#include <limits>
#include <mpi.h>
#include <omp.h>

#include <algorithm>
#include <vector>

namespace openmp {

Centroids InitializeCentroids(const Dataset &local_data, uint32_t num_clusters,
                              uint64_t global_offset, uint64_t total_rows,
                              MPI_Comm comm) {
  const uint32_t num_rows = local_data.n_rows;
  const uint32_t num_cols = local_data.n_cols;

  Centroids centroids;
  centroids.num_clusters = num_clusters;
  centroids.num_cols = num_cols;
  centroids.data.resize(num_clusters * num_cols, 0.0f);
  centroids.counts.resize(num_clusters, 0);

  std::vector<double> local_sums(num_clusters * num_cols, 0.0);
  std::vector<uint32_t> local_counts(num_clusters, 0);

  uint64_t rows_per_cluster = total_rows / num_clusters;
  if (rows_per_cluster == 0) {
    rows_per_cluster = 1;
  }

#pragma omp parallel
  {
    std::vector<double> thread_sums(num_clusters * num_cols, 0.0);
    std::vector<uint32_t> thread_counts(num_clusters, 0);

#pragma omp for nowait
    for (uint32_t r = 0; r < num_rows; ++r) {
      uint64_t global_index = global_offset + r;

      uint32_t cluster_id =
          std::min(static_cast<uint32_t>(global_index / rows_per_cluster),
                   num_clusters - 1);

      thread_counts[cluster_id]++;

      const float *row_ptr = local_data.GetRowPtr(r);
      for (uint32_t c = 0; c < num_cols; ++c) {
        thread_sums[cluster_id * num_cols + c] += row_ptr[c];
      }
    }

#pragma omp critical
    {
      for (uint32_t k = 0; k < num_clusters; ++k) {
        local_counts[k] += thread_counts[k];
        for (uint32_t c = 0; c < num_cols; ++c) {
          local_sums[k * num_cols + c] += thread_sums[k * num_cols + c];
        }
      }
    }
  }

  std::vector<double> global_sums(num_clusters * num_cols, 0.0);

  MPI_Allreduce(local_sums.data(), global_sums.data(), num_clusters * num_cols,
                MPI_DOUBLE, MPI_SUM, comm);
  MPI_Allreduce(local_counts.data(), centroids.counts.data(), num_clusters,
                MPI_UINT32_T, MPI_SUM, comm);

  for (uint32_t k = 0; k < num_clusters; ++k) {
    uint32_t count = centroids.counts[k];
    if (count > 0) {
      for (uint32_t c = 0; c < num_cols; ++c) {
        centroids.data[k * num_cols + c] = static_cast<float>(
            global_sums[k * num_cols + c] / static_cast<double>(count));
      }
    }
  }

  return centroids;
}

Centroids RunKMeans(Dataset &local_data, uint32_t num_clusters,
                    uint32_t max_iterations, uint64_t global_offset,
                    uint64_t total_rows, MPI_Comm comm) {
  int rank = 0;
  int num_procs = 0;
  MPI_Comm_rank(comm, &rank);
  MPI_Comm_size(comm, &num_procs);

  const uint32_t num_cols = local_data.n_cols;

  Centroids centroids = InitializeCentroids(local_data, num_clusters,
                                            global_offset, total_rows, comm);

  std::vector<uint32_t> local_assignments(local_data.n_rows, 0);
  uint64_t rows_per_cluster = total_rows / num_clusters;
  if (rows_per_cluster == 0)
    rows_per_cluster = 1;

  for (uint32_t r = 0; r < local_data.n_rows; ++r) {
    uint64_t global_index = global_offset + r;
    local_assignments[r] =
        std::min(static_cast<uint32_t>(global_index / rows_per_cluster),
                 num_clusters - 1);
  }

  uint32_t iteration = 0;
  bool converged = false;

  while (iteration < max_iterations && !converged) {
    uint64_t local_displacements = 0;
    uint32_t current_num_rows = local_data.n_rows;

#pragma omp parallel
    {
      uint64_t thread_displacement = 0;

#pragma omp for nowait
      for (uint32_t r = 0; r < current_num_rows; ++r) {
        const float *row_ptr = local_data.GetRowPtr(r);

        float min_dist_sq = std::numeric_limits<float>::max();
        uint32_t best_cluster = local_assignments[r];

        for (uint32_t k = 0; k < num_clusters; ++k) {
          const float *centroid_ptr = centroids.GetClusterPtr(k);
          float dist_sq = 0.0f;

          for (uint32_t c = 0; c < num_cols; ++c) {
            float diff = row_ptr[c] - centroid_ptr[c];
            dist_sq += diff * diff;
          }

          if (dist_sq < min_dist_sq) {
            min_dist_sq = dist_sq;
            best_cluster = k;
          }
        }

        if (best_cluster != local_assignments[r]) {
          local_assignments[r] = best_cluster;
          thread_displacement++;
        }
      }

#pragma omp atomic
      local_displacements += thread_displacement;
    }

    uint64_t global_displacement = 0;
    MPI_Allreduce(&local_displacements, &global_displacement, 1, MPI_UINT64_T,
                  MPI_SUM, comm);

    double displacement_ratio = static_cast<double>(global_displacement) /
                                static_cast<double>(total_rows);

    if (displacement_ratio < 0.05) {
      converged = true;
      break;
    }

    iteration++;
  }

  return centroids;
}

} // namespace openmp