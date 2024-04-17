#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

struct data {
  double value;
  std::string date;
  std::string line;
  std::map<std::string, double> dataBase;
  std::map<std::string, double> inputData;
};

class BitcoinExchange {
private:
public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &src);
  ~BitcoinExchange();

  BitcoinExchange &operator=(const BitcoinExchange &rhs);

  void parseDataBase(data &data, const std::string &inputFileName);
  static void btcProgram(const std::string &inputFileName);
};

#endif
