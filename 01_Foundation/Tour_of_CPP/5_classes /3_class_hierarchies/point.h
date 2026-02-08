#ifndef HIERARCHY_POINT_H_
#define HIERARCHY_POINT_H_

#include <cassert>
#include <vector>

namespace hierarchy {

class Point {
public:
  Point() = default;
  explicit Point(const std::vector<double> &coords) : coords_(coords) {}

  const double &operator[](int index) const {
    assert(index >= 0 && index < static_cast<int>(coords_.size()));
    return coords_[index];
  }

  double &operator[](int index) {
    assert(index >= 0 && index < static_cast<int>(coords_.size()));
    return coords_[index];
  }

  const std::vector<double> &coords() const { return coords_; }

private:
  std::vector<double> coords_;
};

} // namespace hierarchy

#endif