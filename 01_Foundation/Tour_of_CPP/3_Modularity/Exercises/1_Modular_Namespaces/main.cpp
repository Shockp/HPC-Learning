// Focus: Separate Compilation; Namespaces
#include "math_utils.h"
#include <iostream>

int main() {
  std::cout << hpc::math::clamp(6.2, 3, 6) << "\n";

  return 0;
}