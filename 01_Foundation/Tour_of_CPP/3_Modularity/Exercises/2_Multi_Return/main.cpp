// Focus: Function Arguments and Return Values (Returning multiple values)

#include "search_result.h"
#include <iostream>
#include <vector>

int main() {
  std::vector list{1, 2, 3, 7, 1, 5};

  auto [is_found, idx] = searchresult::FindValue(list, 7);

  if (is_found) {
    std::cout << "Found at: " << idx << "\n";
  } else {
    std::cout << "Not found.\n";
  }
}