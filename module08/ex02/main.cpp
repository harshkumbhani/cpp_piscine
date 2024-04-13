#include "Span.hpp"

void print_test_name(const std::string &test_name) {
  std::cout << "[TEST] " << test_name << "\n";
}

void testAddAndSize() {
  print_test_name("\nTest Add and Size Limit...");
  Span sp(5);
  try {
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(-2);
    sp.addNumber(9);
    sp.addNumber(11); // Should throw an exception
  } catch (std::exception &e) {
    std::cout << "Expected: " << e.what() << std::endl;
  }
  sp.print();
}

void testShortestSpan() {
  std::cout << "\n[TEST] Test Shortest Span..." << std::endl;
  Span sp(5);
  sp.addNumber(5);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(-2);
  sp.addNumber(9);
  try {
    size_t shortest = sp.shortestSpan();
    std::cout << "Shortest span is: " << shortest << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void testLongestSpan() {
  std::cout << "\n[TEST] Test Longest Span..." << std::endl;
  Span sp(5);
  int numsVector[] = {5, 3, 17, -2, 9, 11};
  std::vector<int> v(numsVector,
                     numsVector + sizeof(numsVector) / sizeof(numsVector[0]));
  sp.floodVector(v.begin(), v.end());
  try {
    size_t longest = sp.longestSpan();
    std::cout << "Longest span is: " << longest << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void testCopyAndAssignment() {
  std::cout << "\n[TEST] Test Copy and Assignment..." << std::endl;
  Span sp1(5);
  sp1.addNumber(5);
  sp1.addNumber(3);

  Span sp2 = sp1; // Test copy constructor
  Span sp3(10);
  sp3 = sp1; // Test assignment operator

  sp1.addNumber(17); // Should not affect sp2 and sp3

  std::cout << "Original Span: " << std::endl;
  sp1.print();

  std::cout << "Copied Span: " << std::endl;
  sp2.print();

  std::cout << "Assigned Span: " << std::endl;
  sp3.print();
}

void testRandFill() {
  Span sp(15);
  int numsVector[] = {5, 3, 17, -2, 9, 11};
  std::vector<int> v(numsVector,
                     numsVector + sizeof(numsVector) / sizeof(numsVector[0]));
  sp.floodVector(v.begin(), v.end());
  sp.addNumber(42);
  std::cout << "\nTest to fill array randomly: \n";
  sp.print();
}

int main() {
  testAddAndSize();
  testShortestSpan();
  testLongestSpan();
  testCopyAndAssignment();
  testRandFill();
  return 0;
}
// int main() {
//   Span sp = Span(5);
//   sp.addNumber(6);
//   sp.addNumber(3);
//   sp.addNumber(17);
//   sp.addNumber(9);
//   sp.addNumber(11);
//   std::cout << sp.shortestSpan() << std::endl;
//   std::cout << sp.longestSpan() << std::endl;
//   return 0;
// }
