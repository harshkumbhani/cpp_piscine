#include "RPN.hpp"

int main(int argc, char *argv[]) {
  RPN rpn;

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <RPN string>" << std::endl;
    return 1;
  }
  try {
    rpn.calculate(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    return 1;
  }
  return 0;
}
