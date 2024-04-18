#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { (void)src; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  (void)rhs;
  return *this;
}

bool isLeapYear(int year) {
  return (((year % 4 == 0) && ((year % 100) != 0)) || (year % 400 == 0));
}

bool dateValidator(std::string &date) {
  calendarDate d;
  struct tm tm = (struct tm){};

  if (!strptime(date.c_str(), "%Y-%m-%d", &tm)) {
    return false;
  }
  std::istringstream ss(date);
  ss >> d.year >> d.c >> d.month >> d.c >> d.date;
  if (d.year < 1)
    return false;

  if (d.month == 2) {
    if (isLeapYear(d.year) == true)
      return (d.date < 30);
    else
      return (d.date < 29);
  }

  if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
    return (d.date < 31);

  return true;
}

void BitcoinExchange::parseDataBase(data &data) {
  std::ifstream file("data.csv");
  if (file.fail() == true)
    throw std::runtime_error("Fail to open data.csv file");

  std::getline(file, data.line);
  ++data.lineNumber;
  while (std::getline(file, data.line)) {
    std::istringstream ss(data.line);

    ++data.lineNumber;
    if (!(std::getline(ss, data.date, ',') && ss >> data.value)) {
      std::cerr << BLUE << std::setw(9) << "Line: " << data.lineNumber
                << "\nContent: " << data.line << RESET << std::endl;
      throw std::runtime_error(
          "Parsing csv file: Undefined characters in data.csv file");
    }
    if (dateValidator(data.date) == false) {
      std::cerr << BLUE << std::setw(9) << "Line: " << data.lineNumber
                << "\nContent: " << data.line << RESET << std::endl;
      throw std::runtime_error(
          "Parsing csv file: Expected format: YYYY-MM-DD (e.g., "
          "2020-01-31).\nEnsure the date is"
          " within a valid range and conforms to the specified format.");
    }
    data.dataBase[data.date] = data.value;
    ss.clear();
  }
  data.lineNumber = 0;
  file.close();
}

void BitcoinExchange::btcProgram(const std::string &inputFile) {
  data d = (data){};
  BitcoinExchange btc;
  btc.parseDataBase(d);

  std::ifstream file(inputFile.c_str());
  if (file.fail() == true)
    throw std::runtime_error("Couldn't open the " + inputFile);

  std::getline(file, d.line);
  while (std::getline(file, d.line)) {
    if (d.line.find('|') == std::string::npos) {
      std::cerr << "Error: bad format, correct Format \" date | value \" "
                << std::endl;
      continue;
    }
    std::istringstream ss(d.line);

    std::getline(ss, d.date, '|');
    ss >> d.value;

    if (dateValidator(d.date) == false) {
      std::cout << "Error: bad input => " << d.date << std::endl;
      continue;
    }

    if (d.value < 0) {
      std::cout << "Error: not a positive number" << std::endl;
      continue;
    }

    if (d.value > 1000) {
      std::cout << "Error: too big a value" << std::endl;
      continue;
    }

    std::map<std::string, double>::iterator it = d.dataBase.lower_bound(d.date);
    if (it == d.dataBase.begin()) {
      std::cout << "Error: Data starts from 2009-01-02 Requested: " << d.date
                << std::endl;
      continue;
    }
    if (d.date < it->first || it == d.dataBase.end())
      --it;
    std::cout << d.date << " => " << d.value << " = " << d.value * it->second
              << std::endl;
    ss.clear();
  }
  file.close();
}
