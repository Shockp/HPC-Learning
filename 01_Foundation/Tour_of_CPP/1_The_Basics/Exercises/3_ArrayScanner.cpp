// Focus: Tests (if/switch); Mapping to Hardware (Arrays)
// Task: Count positive numbers in a list

#include <iostream>
#include <vector>

int CountPositives(const std::vector<int> &numbers) {
  int count = 0;

  for (int number : numbers) {
    if (number > 0) {
      count++;
    }
  }

  return count;
}

int main() {
  const std::vector<int> numbers = {1, -2, 3, 5, 0, -10};

  int result = CountPositives(numbers);

  std::cout << "Positive numbers: " << result << "\n";

  return 0;
}