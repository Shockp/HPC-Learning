#ifndef CONCRETE_COMPLEX_H_
#define CONCRETE_COMPLEX_H_

namespace concrete {
namespace complex {

class Complex {
public:
  constexpr Complex(double r, double i) : re_(r), im_(i) {}
  constexpr Complex(double r) : re_(r), im_(0) {}
  constexpr Complex() : re_(0), im_(0) {}

  constexpr double Real() const { return re_; }
  constexpr void Real(double real) { re_ = real; }

  constexpr double Imag() const { return im_; }
  constexpr void Imag(double imag) { im_ = imag; }

  constexpr Complex &operator+=(const Complex &z);
  constexpr Complex &operator-=(const Complex &z);

private:
  double re_, im_;
};

constexpr Complex &Complex::operator+=(const Complex &z) {
  re_ += z.re_;
  im_ += z.im_;

  return *this;
}

constexpr Complex &Complex::operator-=(const Complex &z) {
  re_ -= z.re_;
  im_ -= z.im_;

  return *this;
}

constexpr Complex operator+(Complex a, const Complex &b) {
  a += b;
  return a;
}

constexpr Complex operator-(Complex a, Complex b) {
  a -= b;
  return a;
}

constexpr Complex operator-(Complex a) { return Complex(-a.Real(), -a.Imag()); }

constexpr bool operator==(Complex a, Complex b) {
  return a.Real() == b.Real() && a.Imag() == b.Imag();
}

constexpr bool operator!=(Complex a, Complex b) { return !(a == b); }

} // namespace complex
} // namespace concrete

#endif
