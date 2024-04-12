#include "Span.hpp"

int main() {
  Span span1(5);

  span1.addNumber(42);
  span1.addNumber(1);
  span1.addNumber(42);
  span1.addNumber(42);
  span1.addNumber(42);

  span1.print();
  // span1.addNumber(42);
  return 0;
}
