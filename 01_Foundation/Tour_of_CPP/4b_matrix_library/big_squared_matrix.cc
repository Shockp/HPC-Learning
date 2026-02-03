#include "big_squared_matrix.h"
#include <cassert>
#include <optional>
#include <stdexcept>

namespace algebra {

BigSquaredMatrix::BigSquaredMatrix(int size, FillMode fillMode) : size_(size) {
  if (size < 0) {
    throw std::invalid_argument("Matrix cannot be negative.");
  }

  data_.resize(size * size, 0);

  switch (fillMode) {
  case algebra::FillMode::kZero:
    break;
  case algebra::FillMode::kIdentity:
    for (int i = 0; i < size; ++i) {
      At(i, i) = 1;
    }
    break;
  case algebra::FillMode::kSequence:
    int64_t counter = 0;
    for (auto &value : data_) {
      value = counter++;
    }
    break;
  }
}

int64_t BigSquaredMatrix::At(int row, int col) const {
  assert(row >= 0 && row < size_);
  assert(col >= 0 && col < size_);

  return data_[row * size_ + col];
}

int64_t &BigSquaredMatrix::At(int row, int col) {
  assert(row >= 0 && row < size_);
  assert(col >= 0 && col < size_);

  return data_[row * size_ + col];
}

std::optional<Point> BigSquaredMatrix::Find(int64_t value) const {
  int total_size = size_ * size_;
  for (int i = 0; i < total_size; ++i) {
    if (data_[i] == value) {
      return Point{i / size_, i % size_};
    }
  }

  return std::nullopt;
}

} // namespace algebra
