#ifndef TEMPLATES_BUFFER_H_
#define TEMPLATES_BUFFER_H_

#include <memory>
namespace templates {

template <typename T, int N> struct Buffer {
  Buffer() : data_(std::make_unique<T[]>(N)) {}

  constexpr int size() { return N; }
  std::unique_ptr<T[]> data_;
};

} // namespace templates

#endif