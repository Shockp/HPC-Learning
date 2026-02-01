// Focus: Enumerations; Unions
/* In HPC, we often treat a chunk of memory as different types
 *  depending on the context (e.g., receiving a network packet)
 */

#include <iostream>
#include <variant>

enum class ValueType { kInteger, kDouble };

struct Message {
  std::variant<int, double> payload;
  ValueType type;
};

void PrintMessage(const Message &m) {
  switch (m.type) {
  case ValueType::kInteger:
    std::cout << "Integer: " << std::get<int>(m.payload) << "\n";
    break;
  case ValueType::kDouble:
    std::cout << "Double: " << std::get<double>(m.payload) << "\n";
    break;
  }
}

int main() {
  Message msg;

  msg.type = ValueType::kDouble;
  msg.payload = 5.345;

  PrintMessage(msg);

  return 0;
}