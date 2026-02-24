#include <cstdint>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <vector>

#include <mpi.h>

#include "../include/io_utils.h"
#include "../include/models/dataset.h"

/**
 * @brief Main entry point for the MPI-based dataset distribution program.
 *
 * This program initializes an MPI environment, reads a binary dataset file
 * from the root process (rank 0), and then distributes the dataset rows
 * across all available MPI processes using MPI_Scatterv. Load balancing
 * is applied if the total number of rows is not perfectly divisible by
 * the number of processes.
 *
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 * @return EXIT_SUCCESS upon successful completion, EXIT_FAILURE on error.
 */
int main(int argc, char **argv) {
  // Initialize the MPI execution environment
  MPI_Init(&argc, &argv);

  int rank = 0;
  int num_procs = 0;
  // Get the rank of the calling process in the communicator
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  // Get the number of processes in the communicator
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

  openmp::Dataset global_dataset;
  uint32_t dimensions[2] = {0, 0};

  // Rank 0 is responsible for reading the dataset from the disk
  if (rank == 0) {
    try {
      global_dataset = openmp::ReadBinaryFile("../data/dataset.bin");
      dimensions[0] = global_dataset.n_rows;
      dimensions[1] = global_dataset.n_cols;
      std::cout << "[Rank 0] Successfully loaded " << dimensions[0]
                << " rows and " << dimensions[1] << " columns.\n";
    } catch (const std::exception &e) {
      std::cerr << "[Rank 0] Error: " << e.what() << "\n";
      // Abort all MPI processes if file reading fails
      MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
  }

  // Broadcast the dataset dimensions (rows and columns) from rank 0 to all
  // other processes
  MPI_Bcast(dimensions, 2, MPI_UINT32_T, 0, MPI_COMM_WORLD);

  uint32_t total_rows = dimensions[0];
  uint32_t num_cols = dimensions[1];

  // Calculate the number of rows each process will handle.
  // Distribute the remainder rows among the first 'remainder' processes.
  int local_rows = total_rows / num_procs;
  int remainder = total_rows % num_procs;
  if (rank < remainder) {
    local_rows++;
  }

  // Arrays to hold the number of MPI elements to send to each process and their
  // relative displacements
  std::vector<int> sendcounts(num_procs, 0);
  std::vector<int> displacements(num_procs, 0);

  // Rank 0 calculates the exact chunk sizes and offsets for the scatter
  // operation
  if (rank == 0) {
    int current_displacement = 0;
    for (int i = 0; i < num_procs; ++i) {
      int rows_for_proc = total_rows / num_procs + (i < remainder ? 1 : 0);
      sendcounts[i] = rows_for_proc * num_cols;
      displacements[i] = current_displacement;
      current_displacement += sendcounts[i];
    }
  }

  // Initialize the local dataset for each process
  openmp::Dataset local_dataset;
  local_dataset.n_rows = local_rows;
  local_dataset.n_cols = num_cols;
  local_dataset.data.resize(local_rows * num_cols);

  // Scatter the dataset data from rank 0 to all processes.
  // MPI_Scatterv allows scattering chunks of different sizes if division is
  // uneven.
  MPI_Scatterv(global_dataset.data.data(), sendcounts.data(),
               displacements.data(), MPI_FLOAT, local_dataset.data.data(),
               local_rows * num_cols, MPI_FLOAT, 0, MPI_COMM_WORLD);

  // Synchronize all processes to ensure data distribution is complete before
  // proceeding
  MPI_Barrier(MPI_COMM_WORLD);

  // Print confirmation of received data for each process
  std::cout << "[Rank " << rank << "] Received " << local_dataset.n_rows
            << " rows. (Total elements: " << local_dataset.data.size() << ")\n";

  // Terminate the MPI execution environment
  MPI_Finalize();
  return EXIT_SUCCESS;
}