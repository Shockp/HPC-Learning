// Focus: Pointers, Arrays, and References; Scope and Lifetime
// Task: Implement two increment functions

#include <iostream>

constexpr void IncrementPtr(int* ptr_value) {
    if (ptr_value != nullptr) {
        (*ptr_value)++;
    }
}

constexpr void IncrementRef(int& ref_value) {
    ref_value++;
}

int main() {
    int x = 5;

    IncrementPtr(&x);

    std::cout << "Value after pointer increment: " << x << "\n";

    IncrementRef(x);

    std::cout << "Final value: " << x << "\n";

    return 0;
}