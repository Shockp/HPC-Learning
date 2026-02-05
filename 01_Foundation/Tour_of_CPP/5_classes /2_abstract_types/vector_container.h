#ifndef ABSTRACT_VECTOR_H_
#define ABSTRACT_VECTOR_H_

#include "../1_concrete_types/vector.h"
#include "container.h"

namespace abstract {
namespace vector {

class Vector : public container::Container {
public:
  Vector(int s) : v_{s} {}
  ~Vector() {}

  double &operator[](int i) { return v_[i]; }

  int size() const { return v_.size(); }

private:
  concrete::vector::Vector v_;
};

} // namespace vector
} // namespace abstract

#endif
