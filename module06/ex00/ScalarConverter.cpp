#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convertFromChar(char c) {
  if (std::isprint(c))
    std::cout << "char: " << c << std::endl;
  else
    std::cout << "char: Non-displayable character" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << "\n"
            << std::fixed << std::setprecision(1)
            << "float: " << static_cast<float>(c) << "f\n"
            << "double: " << static_cast<double>(c) << std::endl;
}

Type ScalarConverter::checkType(std::string &literal, data &d) {
  std::istringstream input(literal);

  if (literal.length() == 1 && std::isprint(literal[0])) {
    d.charValue = literal[0];
    // input >> d.charValue;
    return CHAR;
  }
  return UNKNOWN;
}

void ScalarConverter::convert(const std::string &input) {
  data d;
  std::string literal = input;
  ScalarConverter converter;
  Type type = converter.checkType(literal, d);
  switch (type) {
  case CHAR:
    converter.convertFromChar(d.charValue);
    break;
  case INT:
    break;
  case FLOAT:
    break;
  case DOUBLE:
    break;
  default:
    std::cout << "Invalid input argument" << std::endl;
    break;
  }
}
