#ifndef TEMPLATES_MECHANISMS_H_
#define TEMPLATES_MECHANISMS_H_

#include "../1_parameterized_types/vector.h"
#include <iostream>
#include <type_traits>

namespace mechanisms {

template <typename T> constexpr T kTolerance = T(0.1);
template <> constexpr double kTolerance<double> = 0.0001;

template <typename T> using Vec3D = templates::Vector<T>;

template <typename T> auto SmartAverage(T a, T b) {
  if constexpr (std::is_pointer_v<T>) {
    return (*a + *b) / 2.0;
  } else if constexpr (std::is_floating_point_v<T>) {
    return (a + b) / 2.0;
  } else {
    std::cout << "WARNING! This is an integer division." << "\n";
    return (a + b) / 2;
  }
}

} // namespace mechanisms

#endif