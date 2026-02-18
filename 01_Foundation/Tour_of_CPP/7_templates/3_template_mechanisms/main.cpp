#include "mechanisms.h"
#include <iostream>

int main() {
  double num1 = 5.5;
  double num2 = 4.3;
  int num3 = 1;
  int num4 = 2;
  double *p1 = &num1;
  double *p2 = &num2;

  std::cout << mechanisms::SmartAverage(num1, num2) << "\n";
  std::cout << mechanisms::SmartAverage(num3, num4) << "\n";
  std::cout << mechanisms::SmartAverage(p1, p2) << "\n";
  std::cout << mechanisms::kTolerance<float> << "\n";
  std::cout << mechanisms::kTolerance<double> << "\n";

  mechanisms::Vec3D<int> my_vector(3);
  std::cout << "Vec3D Size: " << my_vector.size() << "\n";

  return 0;
}