#ifndef TEMPLATES_VECTOR_H_
#define TEMPLATES_VECTOR_H_

#include <algorithm>
#include <cassert>
#include <memory>

namespace templates {

template <typename T> class Vector {
public:
  explicit Vector(int size) : size_(size), data_(std::make_unique<T[]>(size)) {
    assert(size_ >= 0);
  }

  T &operator[](int index) {
    assert(index >= 0 && index < size_);
    return data_[index];
  }
  const T &operator[](int index) const {
    assert(index >= 0 && index < size_);
    return data_[index];
  }

  Vector(const Vector &other)
      : size_(other.size_), data_(std::make_unique<T[]>(other.size_)) {
    std::copy(other.begin(), other.end(), this->begin());
  }
  Vector<T> &operator=(const Vector &other) {
    if (this == &other) {
      return *this;
    }

    size_ = other.size_;
    data_ = std::make_unique<T[]>(other.size_);
    std::copy(other.begin(), other.end(), this->begin());

    return *this;
  }

  Vector(Vector &&) = default;
  Vector<T> &operator=(Vector &&) = default;

  int size() const { return size_; }

  T *begin() { return data_.get(); }
  T *end() { return data_.get() + size_; }
  const T *begin() const { return data_.get(); }
  const T *end() const { return data_.get() + size_; }

private:
  int size_;
  std::unique_ptr<T[]> data_;
};

} // namespace templates

#endif