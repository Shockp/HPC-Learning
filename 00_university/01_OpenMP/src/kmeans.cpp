#include "../include/kmeans.h"

#include <cstdint>
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

} // namespace openmp