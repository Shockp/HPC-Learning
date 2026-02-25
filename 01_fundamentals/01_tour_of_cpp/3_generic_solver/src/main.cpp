#include <iostream>
#include <string>
#include <vector>

#include "../include/linear_system.h"

template <typename T>
void PrintSolution(const std::string &type_name, const std::vector<T> &sol) {
  std::cout << "Solution (" << type_name << "): [ ";
  for (const auto &val : sol) {
    std::cout << val << " ";
  }
  std::cout << "]\n";
}

int main() {
  // System of equations:
  //  2.0x + 1.0y - 1.0z =   8.0
  // -3.0x - 1.0y + 2.0z = -11.0
  // -2.0x + 1.2y + 2.0z =  -3.0

  std::cout << "--- Testing double (High Precision) ---\n";
  std::vector<double> matrix_double = {2.0, 1.0,   -1.0, 8.0, -3.0, -1.0,
                                       2.0, -11.0, -2.0, 1.2, 2.0,  -3.0};
  genericsolver::LinearSystem<double> sys_double(3, matrix_double);
  std::vector<double> sol_double = sys_double.Solve();
  PrintSolution("double", sol_double);

  std::cout << "\n--- Testing float (High Speed) ---\n";
  std::vector<float> matrix_float = {2.0f, 1.0f,   -1.0f, 8.0f, -3.0f, -1.0f,
                                     2.0f, -11.0f, -2.0f, 1.2f, 2.0f,  -3.0f};
  genericsolver::LinearSystem<float> sys_float(3, matrix_float);
  std::vector<float> sol_float = sys_float.Solve();
  PrintSolution("float", sol_float);

  // --- Testing the static_assert Boundary ---
  // Uncomment the lines below. The compiler will halt and print:
  // "LinearSystem strictly requires a floating-point type..."

  /*
  std::vector<std::string> matrix_string = {"a", "b", "c", "d"};
  LinearSystem<std::string> sys_string(1, matrix_string);
  */

  return 0;
}