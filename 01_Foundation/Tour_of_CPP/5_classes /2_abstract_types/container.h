#ifndef ABSTRACT_CONTAINER_H_
#define ABSTRACT_CONTAINER_H_

namespace abstract {
namespace container {

class Container {
public:
  virtual double &operator[](int) = 0;
  virtual int size() const = 0;
  virtual ~Container() {}
};

} // namespace container
} // namespace abstract

#endif
