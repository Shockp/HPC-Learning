// Focus: Return values; Advice (Move Semantics)

#include "big_vector.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> my_vector = bigvector::CreateBigVector(1000);

  std::cout << sizeof(my_vector) << "\n";

  return 0;
}