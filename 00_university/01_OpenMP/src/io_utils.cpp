#include "../include/io_utils.h"

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <stdexcept>

namespace openmp {

/**
 * @brief Implementation of ReadBinaryFile.
 *
 * @copydetails ReadBinaryFile
 */
Dataset ReadBinaryFile(const std::string &filepath) {
  Dataset dataset;

  std::ifstream file(filepath, std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filepath);
  }

  file.read(reinterpret_cast<char *>(&dataset.n_rows), sizeof(uint32_t));
  file.read(reinterpret_cast<char *>(&dataset.n_cols), sizeof(uint32_t));

  if (!file) {
    throw std::runtime_error("Failed to read dataset dimensions.");
  }

  const size_t total_elements =
      static_cast<size_t>(dataset.n_rows) * dataset.n_cols;

  dataset.data.resize(total_elements);

  file.read(reinterpret_cast<char *>(dataset.data.data()),
            total_elements * sizeof(float));

  if (!file) {
    throw std::runtime_error(
        "Error reading dataset values or EOF reached unexpectedly.");
  }

  return dataset;
}

} // namespace openmp