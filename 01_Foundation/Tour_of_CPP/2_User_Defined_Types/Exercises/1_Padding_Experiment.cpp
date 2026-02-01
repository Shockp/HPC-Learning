// Focus: Structurres, Memory Alignment
/* In HPC, we care about sizeof because memory bandwidth is our bottleneck.
C++ adds "padding" bytes between variables to align them to memory addresses,
which can waste up to 50% of your RAM if you are careless.
*/

#include <iostream>

struct BadParticle {
  char type;       // 1 byte
  double position; // 8 bytes
  char active;     // 1 byte
};

struct GoodParticle {
  double position; // 8 bytes
  char type;       // 1 byte
  char active;     // 1 byte
};

int main() {
  std::cout << sizeof(BadParticle) << "\n";
  std::cout << sizeof(GoodParticle) << "\n";

  return 0;
}