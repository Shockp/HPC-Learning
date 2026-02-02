#include "math_utils.h"

namespace hpc {
namespace math {

double clamp(double value, double min, double max) {
  if (value < min) return min;
  if (value < max) return max;
  return value;
}

} // namespace math
} // namespace hpc
