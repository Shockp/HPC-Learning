// Focus: Classes; Encapsulation; Invariants
// Task: Create a class GridDimension
#include <iostream>

class GridDimension {
public:
  GridDimension(int w, int h)
      : width_((w > 0) ? w : 0), height_((h > 0) ? h : 0) {}

  int CalculateArea() const { return width_ * height_; }

private:
  int width_;
  int height_;
};

int main() {
  int w = 0;
  int h = 0;

  std::cout << "Width: ";
  std::cin >> w;

  std::cout << "Height: ";
  std::cin >> h;

  GridDimension grid(w, h);

  std::cout << "Area: " << grid.CalculateArea() << "\n";

  return 0;
}