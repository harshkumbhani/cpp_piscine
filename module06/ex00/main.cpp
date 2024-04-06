#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {

  (void)argv;
  if (argc != 2) {
    std::cerr << "Usage: ./converter '<char> | <int> | <float> | <double>'"
              << std :: endl;
    return EXIT_FAILURE;
  }

  ScalarConverter::convert(argv[1]);
  return 0;
}
