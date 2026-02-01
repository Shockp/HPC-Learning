// Focus: Enumerations; Unions
/* In HPC, we often treat a chunk of memory as different types
 *  depending on the context (e.g., receiving a network packet)
 */

#include <iostream>

enum class ValueType { kInteger, kDouble };

union Payload {
  int int_val;
  double double_val;
};

struct Message {
  ValueType type;
  Payload data;
};

void PrintMessage(const Message &m) {
  switch (m.type) {
  case ValueType::kInteger:
    std::cout << "Integer: " << m.data.int_val << "\n";
    break;
  case ValueType::kDouble:
    std::cout << "Double: " << m.data.double_val << "\n";
    break;
  }
}

int main() {
  Message msg;

  msg.type = ValueType::kDouble;
  msg.data.double_val = 5.345;

  PrintMessage(msg);

  return 0;
}