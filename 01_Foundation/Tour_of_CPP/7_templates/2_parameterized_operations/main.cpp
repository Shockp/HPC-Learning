#include "../1_parameterized_types/vector.h"
#include "operations.h"
#include <iostream>

struct Scale {
  int factor;

  explicit Scale(int f) : factor(f) {}

  int operator()(int x) const { return x * factor; }
};

int main() {
  templates::Vector<int> v(5);

  int start_val = 0;
  operations::Generate(v, [n = start_val]() mutable { return ++n; });

  operations::Transform(v, Scale(3));

  operations::Transform(v, [](int x) { return x + 10; });

  int limit = 15;
  operations::Transform(v, [limit](int x) { return (x > limit) ? limit : x; });

  std::cout << "Pipeline Resul: ";
  operations::ForEach(v, [](int x) { std::cout << x << " "; });
  std::cout << "\n";

  return 0;
}