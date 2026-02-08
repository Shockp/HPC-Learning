#ifndef OPERATIONS_VECTOR_H_
#define OPERATIONS_VECTOR_H_

#include <algorithm>
#include <memory>

namespace operations {

class Vector {
public:
  explicit Vector(int size)
      : size_(size), data_(std::make_unique<int[]>(size)) {}
  ~Vector() = default;

  // Copy constructor
  Vector(const Vector &other)
      : size_(other.size_), data_(std::make_unique<int[]>(other.size_)) {

    std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
  }
  // Copy assignment
  Vector &operator=(const Vector &other) {
    if (this == &other) {
      return *this;
    }

    if (size_ != other.size_) {
      size_ = other.size();
      data_ = std::make_unique<int[]>(size_);
    }

    std::copy(other.data_.get(), other.data_.get() + size_, data_.get());

    return *this;
  }

  // Move constructor and assignment
  // Because we defined a custom constructor, the compiler deleted these.
  // We can use default because unique_ptr knows how to move efficiently
  Vector(Vector &&) = default;
  Vector &operator=(Vector &&) = default;

  // Write
  int &operator[](int index) { return data_[index]; }
  // Read
  const int &operator[](int index) const { return data_[index]; }

  int size() const { return size_; }

private:
  int size_;
  std::unique_ptr<int[]> data_;
};

} // namespace operations

#endif