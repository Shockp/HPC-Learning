#ifndef CONCRETE_VECTOR_H_
#define CONCRETE_VECTOR_H_

namespace concrete {
namespace vector {

class Vector {
public:
  Vector(int size) : data_{new double[size]()}, size_{size} {}
  Vector(const Vector &a) : data_{new double[a.size_]}, size_{a.size_} {
    for (int i = 0; i < size_; ++i) {
      this->data_[i] = a.data_[i];
    }
  }

  ~Vector() { delete[] data_; }

  double &operator[](int i);
  int size() const;

private:
  double *data_;
  int size_;
};

} // namespace vector
} // namespace concrete

#endif
