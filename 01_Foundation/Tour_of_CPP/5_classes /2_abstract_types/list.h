#ifndef ABSTRACT_LIST_H_
#define ABSTRACT_LIST_H_

#include "container.h"
#include <initializer_list>
#include <list>
#include <stdexcept>

namespace abstract {

class List : public Container {
public:
  List() = default;
  List(std::initializer_list<double> il) : dlist_(il) {}
  ~List() = default;

  double &operator[](int) override;
  int size() const override { return dlist_.size(); }

private:
  std::list<double> dlist_;
};

inline double &List::operator[](int i) {
  for (auto &x : dlist_) {
    if (i == 0) {
      return x;
    }
    --i;
  }
  throw std::out_of_range("List container");
}

} // namespace abstract

#endif