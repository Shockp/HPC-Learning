#ifndef HIERARCHY_POINT_H_
#define HIERARCHY_POINT_H_

#include <cassert>
#include <vector>
namespace hierarchy {

class Point {
public:
  Point() = default;
  explicit Point(const std::vector<int> &coords) : coords_(coords) {}

  const int &operator[](int index) const {
    assert(index >= 0 && index < static_cast<int>(coords_.size()));
    return coords_[index];
  }

  int &operator[](int index) {
    assert(index >= 0 && index < static_cast<int>(coords_.size()));
    return coords_[index];
  }

  const std::vector<int> &Coords() const { return coords_; }

private:
  std::vector<int> coords_;
};

} // namespace hierarchy

#endif