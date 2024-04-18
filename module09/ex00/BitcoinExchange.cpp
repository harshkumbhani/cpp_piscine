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

bool isValidDate(calendarDate &d) {
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

void dateValidator(data &data) {
  calendarDate d;
  struct tm tm = (struct tm){};

  if (!strptime(data.date.c_str(), "%Y-%m-%d", &tm)) {
    std::cerr << BLUE << std::setw(9) << "Line: " << data.lineNumber
              << "\nContent: " << data.line << RESET << std::endl;
    throw std::runtime_error(
        "Expected format: YYYY-MM-DD (e.g., 2020-01-31).\nEnsure the date is "
        "within a valid range and conforms to the specified format.");
  }
  std::istringstream ss(data.date);
  ss >> d.year >> d.c >> d.month >> d.c >> d.date;
  if (isValidDate(d) == false) {
    std::cerr << BLUE << std::setw(9) << "Line: " << data.lineNumber
              << "\nContent: " << data.line << RESET << std::endl;
    throw std::runtime_error("Date not within valid range");
  }
}

void BitcoinExchange::parseDataBase(data &data,
                                    const std::string &inputFileName) {
  (void)inputFileName;
  std::ifstream file("test.csv");
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
          "Parsing: Undefined characters in data.csv file");
    }
    dateValidator(data);
    data.dataBase[data.date] = data.value;
    ss.clear();
  }
  data.lineNumber = 0;
  file.close();
}

void BitcoinExchange::btcProgram(const std::string &inputFileName) {
  data d = (data){};
  BitcoinExchange btc;
  (void)inputFileName;
  btc.parseDataBase(d, inputFileName);
}
