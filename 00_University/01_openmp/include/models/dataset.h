#ifndef UNIVERSITY_OPENMP_MODELS_DATASET_H_
#define UNIVERSITY_OPENMP_MODELS_DATASET_H_

#include <cstdint>
#include <vector>

namespace models {

struct Dataset {
  uint32_t n_rows;
  uint32_t n_cols;
  std::vector<float> data;

  
};

} // namespace models

#endif // UNIVERSITY_OPENMP_MODELS_DATASET_H_
