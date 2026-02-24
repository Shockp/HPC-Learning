#ifndef UNIVERSITY_OPENMP_MODELS_DATASET_H_
#define UNIVERSITY_OPENMP_MODELS_DATASET_H_

#include <cstdint>
#include <vector>

namespace models {

struct Dataset {
  uint32_t n_rows;
  uint32_t n_cols;
  std::vector<float> data;

  inline float GetValue(uint32_t row, uint32_t col) const {
    return data[row * n_cols + col];
  }

  inline const float *GetRowPtr(uint32_t row) const {
    return &data[row * n_cols];
  }

  inline float *GetRowPtr(uint32_t row) { return &data[row * n_cols]; }
};

} // namespace models

#endif // UNIVERSITY_OPENMP_MODELS_DATASET_H_
