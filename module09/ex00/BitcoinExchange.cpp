#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { (void)src; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  (void)rhs;
  return *this;
}

void BitcoinExchange::parseDataBase(data &data,
                                    const std::string &inputFileName) {
  std::ifstream file("data.csv".c_str());
  if (file.fail() == true)


}

void BitcoinExchange::btcProgram(const std::string &inputFileName) {
  data d;
  BitcoinExchange btc;

  btc.parseDataBase(d, inputFileName);
}
