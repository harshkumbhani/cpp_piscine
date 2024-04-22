#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
  PmergeMe tosort;

  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <int_1> <int_2> ..... <int_n>"
              << std::endl;
    return 1;
  }
  try {
    tosort.sortMe(argc, argv);
  } catch (const std::exception &e) {
    std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    return 1;
  }
  return 0;
}
