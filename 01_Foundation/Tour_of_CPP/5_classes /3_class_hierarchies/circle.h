#ifndef HIERARCHY_CIRCLE_H_
#define HIERARCHY_CIRCLE_H_

#include "point.h"
#include "shape.h"

namespace hierarchy {

class Circle : public Shape {
public:
  Circle(const Point &p, double radius) : center_(p), radius_(radius) {}

  Point center() const override { return center_; }
  void move(const Point &to) override { center_ = to; }
  void draw() const override;
  void rotate(int) override {}

private:
  Point center_;
  double radius_;
};

} // namespace hierarchy

#endif