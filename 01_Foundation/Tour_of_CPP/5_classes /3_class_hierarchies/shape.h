#ifndef HIERARCHY_SHAPE_H_
#define HIERARCHY_SHAPE_H_

#include "point.h"

namespace hierarchy {

class Shape {
public:
  virtual ~Shape() = default;

  virtual Point center() const = 0;
  virtual void move(Point to) = 0;
  virtual void draw() const = 0;
  virtual void rotate(int angle) = 0;
};

} // namespace hierarchy

#endif