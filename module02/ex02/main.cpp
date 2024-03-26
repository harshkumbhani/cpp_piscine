#include "Fixed.hpp"

int main() {
  Fixed a(5.5f);
  Fixed b(2);
  Fixed c = a + b;
  Fixed d = a - b;
  Fixed e = a * b;
  Fixed f = a / b;

  std::cout << std::boolalpha;
  // Arithmetic Operations Section
  std::cout << "\n-----------------------\n";
  std::cout << "Arithmetic Operations:\n";
  std::cout << "-----------------------\n";
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "a + b = " << c << std::endl;
  std::cout << "a - b = " << d << std::endl;
  std::cout << "a * b = " << e << std::endl;
  std::cout << "a / b = " << f << "\n\n";

  // Comparison Operators Section
  std::cout << "-----------------------\n";
  std::cout << "Comparison Operations:\n";
  std::cout << "-----------------------\n";
  std::cout << "a > b: " << (a > b) << std::endl;
  std::cout << "a < b: " << (a < b) << std::endl;
  std::cout << "a >= b: " << (a >= b) << std::endl;
  std::cout << "a <= b: " << (a <= b) << std::endl;
  std::cout << "a == b: " << (a == b) << std::endl;
  std::cout << "a != b: " << (a != b) << "\n\n";

  // Increment/Decrement Operators Section
  std::cout << "-----------------------\n";
  std::cout << "Increment/Decrement Operations:\n";
  std::cout << "-----------------------\n";
  std::cout << "Initial value of a: " << a << std::endl;
  std::cout << "++a = " << ++a << std::endl;
  std::cout << "a++ (Value before increment: " << a++
            << ", Value after increment: " << a << ")\n";
  std::cout << "--a = " << --a << std::endl;
  std::cout << "a-- (Value before decrement: " << a--
            << ", Value after decrement: " << a << ")\n\n";

  // Static min/max Functions Section
  const Fixed g(3.14f);
  const Fixed h(2.71f);
  std::cout << "-----------------------\n";
  std::cout << "Static min/max Operations:\n";
  std::cout << "-----------------------\n";
  std::cout << "g = " << g << ", h = " << h << std::endl;
  std::cout << "Min of g and h = " << Fixed::min(g, h) << std::endl;
  std::cout << "Max of g and h = " << Fixed::max(g, h) << std::endl;
  std::cout << "-----------------------\n";
  std::cout << "End of test\n" << std::endl;
  return (0);
}
