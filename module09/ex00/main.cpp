#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  (void)argv;
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <inputFileName> "  << std::endl;
    return 1;
  }
  try {
  BitcoinExchange::btcProgram(argv[1]);
  } catch (const std::runtime_error &e) {
    std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    return 1;
  }
  return 0;
}
