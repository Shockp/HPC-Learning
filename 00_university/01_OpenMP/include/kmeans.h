#ifndef UNIVERSITY_OPENMP_KMEANS_H_
#define UNIVERSITY_OPENMP_KMEANS_H_

#include "models/centroids.h"
#include "models/dataset.h"

#include <mpi.h>

#include <cstdint>

namespace openmp {

Centroids InitializeCentroids(const Dataset &local_data, uint32_t num_clusters,
                              uint64_t global_offset, uint64_t total_rows,
                              MPI_Comm comm);

Centroids RunKMeans(Dataset &local_data, uint32_t num_clusters,
                    uint32_t max_iterations, uint64_t global_offset,
                    uint64_t total_rows, MPI_Comm comm);

} // namespace openmp

#endif // UNIVERSITY_OPENMP_KMEANS_H_