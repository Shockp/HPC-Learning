// Focus: Functions; Types; Arithmetic; Constants (const vs constexpr)
// Task: Write a function to calculate sphere volume

#include <iostream>

constexpr double kPi = 3.1415926535;

constexpr double SphereVolume(double radius) {
    return (4.0 / 3.0) * kPi * radius * radius * radius;
}

int main() {
    constexpr double volume = SphereVolume(5.0);
    
    std::cout << "Volume: " << volume << "\n";
    return 0;
}