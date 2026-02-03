#ifndef ALGEBRA_H_
#define ALGEBRA_H_

#include <cstdint>
#include <optional>
#include <vector>

namespace algebra {

enum class FillMode { kZero, kIdentity, kSequence };

struct Point {
  int row;
  int col;
};

class BigSquaredMatrix {
public:
  BigSquaredMatrix(int size, FillMode fillMode);

  int64_t At(int row, int col) const;
  int64_t &At(int row, int col);
  std::optional<Point> Find(int64_t value) const;

private:
  int size_;
  std::vector<int64_t> data_;
};

} // namespace algebra

#endif