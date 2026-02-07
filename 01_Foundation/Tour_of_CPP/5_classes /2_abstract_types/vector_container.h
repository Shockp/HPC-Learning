#ifndef ABSTRACT_VECTOR_H_
#define ABSTRACT_VECTOR_H_

#include "../1_concrete_types/vector.h"
#include "container.h"

namespace abstract {

class Vector : public Container {
public:
  Vector(int s) : v_{s} {}
  ~Vector() = default;

  double &operator[](int i) override { return v_[i]; }

  int size() const override { return v_.size(); }

private:
  concrete::vector::Vector v_;
};

} // namespace abstract

#endif
