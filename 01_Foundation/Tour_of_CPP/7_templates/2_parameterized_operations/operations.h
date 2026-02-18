#ifndef TEMPLATES_OPERATIONS_H_
#define TEMPLATES_OPERATIONS_H_

namespace operations {

template <typename Container, typename Generator>
void Generate(Container &c, Generator gen) {
  for (auto &element : c) {
    element = gen();
  }
}

template <typename Container, typename UnaryOp>
void Transform(Container &c, UnaryOp op) {
  for (auto &element : c) {
    element = op(element);
  }
}

template <typename Container, typename Visitor>
void ForEach(Container &c, Visitor visitor) {
  for (auto &element : c) {
    element = visitor(element);
  }
}

} // namespace operations

#endif