#include <cassert>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <vector>

class SquareMatrix {
public:
  SquareMatrix(int size) : size_(size) {
    if (size <= 0) {
      throw std::invalid_argument("Matrix size must be greater than 0.");
    }

    data_.resize(size * size, 0.0);
  }

  // Read-Write
  double &At(int row, int col) {
    assert(row >= 0 && row < size_);
    assert(col >= 0 && col < size_);

    return data_[row * size_ + col];
  }

  // Read
  const double &At(int row, int col) const {
    assert(row >= 0 && row < size_);
    assert(col >= 0 && col < size_);

    return data_[row * size_ + col];
  }

  std::optional<std::pair<int, int>> FindElement(double value) const {
    for (int i = 0; i < size_ * size_; i++) {
      if (data_[i] == value) {
        return std::pair{i / size_, i % size_};
      }
    }

    return std::nullopt;
  }

  int size() const { return size_; }

private:
  int size_;
  std::vector<double> data_;
};

int main() {
  SquareMatrix matrix(3);

  matrix.At(2, 2) = 5.0;
  matrix.At(1, 2) = 2.0;
  matrix.At(0, 0) = 1.5;

  auto result = matrix.FindElement(2.0);

  if (result.has_value()) {
    auto [row, col] = result.value();
    std::cout << "Found 2.0 at: [" << row << "," << col << "]\n";
  } else {
    std::cout << "Value not found.";
  }

  return 0;
}