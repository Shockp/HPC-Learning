#include "big_vector.h"

std::vector<int> bigvector::CreateBigVector(int size) {
  std::vector<int> temp_vector;
  temp_vector.reserve(size);

  for (int i = 0; i < size; ++i) {
    temp_vector.push_back(i);
  }

  return temp_vector;
}