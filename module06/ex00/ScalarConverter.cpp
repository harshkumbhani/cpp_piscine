#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convertFromChar(char c) {
  std::cout << "char: '" << c << "'\n"
            << "int: " << static_cast<int>(c) << "\n"
            << std::fixed << std::setprecision(1)
            << "float: " << static_cast<float>(c) << "f\n"
            << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(long num) {

  if (num < std::numeric_limits<char>::min() ||
      num > std::numeric_limits<char>::max())
    std::cout << "char: overflow" << std::endl;
  else if (std::isprint(static_cast<char>(num)))
    std::cout << "char: '" << static_cast<char>(num) << "'\n";
  else
    std::cout << "char: "
              << "Non displayable" << std::endl;

  if (num < std::numeric_limits<int>::min() ||
      num > std::numeric_limits<int>::max())
    std::cout << "int: overflow" << std::endl;
  else
    std::cout << "int: " << num << "\n";
  std::cout << std::fixed << std::setprecision(1)
            << "float: " << static_cast<float>(num) << "f\n"
            << "double: " << static_cast<double>(num) << std::endl;
}

void ScalarConverter::convertFromFloat(double num) {

  if (num < std::numeric_limits<char>::min() ||
      num > std::numeric_limits<char>::max())
    std::cout << "char: overflow" << std::endl;
  else if (std::isprint(static_cast<char>(num)))
    std::cout << "char: '" << static_cast<char>(num) << "'\n";
  else
    std::cout << "char: "
              << "Non displayable" << std::endl;

  if (num < std::numeric_limits<int>::min() ||
      num > std::numeric_limits<int>::max())
    std::cout << "int: overflow" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(num) << "\n";
  std::cout << std::fixed;

  std::cout << "float: " << num << "f\n";
  std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void ScalarConverter::convertFromDouble(long double num) {

  if (num < std::numeric_limits<char>::min() ||
      num > std::numeric_limits<char>::max())
    std::cout << "char: overflow" << std::endl;
  else if (std::isprint(static_cast<char>(num)))
    std::cout << "char: '" << static_cast<char>(num) << "'\n";
  else
    std::cout << "char: "
              << "Non displayable" << std::endl;

  if (num < std::numeric_limits<int>::min() ||
      num > std::numeric_limits<int>::max())
    std::cout << "int: overflow" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(num) << "\n";
  std::cout << std::fixed;

  std::cout << "float: " << static_cast<float>(num) << "f\n";
  std::cout << "double: " << num << "f\n";
}

void ScalarConverter::convertPseudoLiteral(std::string &literal, bool isFloat) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;

  std::string floatString = literal;
  std::string doubleString = literal;

  if (isFloat == true) {
    if (literal == "inff") {
      floatString = "+inff";
      doubleString = "+inff";
    }
    doubleString = literal.substr(0, literal.length() - 1);
  } else {
    if (literal == "inf") {
      doubleString = "+inf";
      floatString = "+inf";
    }
    floatString += "f";
  }

  std::cout << "float: " << floatString << std::endl;
  std::cout << "double: " << doubleString << std::endl;
}

Type ScalarConverter::checkType(std::string &literal, data &d) {
  std::istringstream input(literal);

  if (literal == "nan" || literal == "-inf" || literal == "+inf" ||
      literal == "inf") {
    d.isPseudoFloat = false;
    return PSEUDO_LITERAL;
  }

  if (literal == "nanf" || literal == "-inff" || literal == "+inff" ||
      literal == "inff") {
    d.isPseudoFloat = true;
    return PSEUDO_LITERAL;
  }

  if (literal.length() == 1 && std::isprint(literal[0]) &&
      std::isdigit(literal[0]) == false) {
     d.charValue = literal[0];
    return CHAR;
  }

  input.clear();
  input.str(literal);
  input >> d.intValue;
  if (input.fail() == false && input.eof() == true) {
    return INT;
  }

  input.clear();
  std::string::reverse_iterator itr = literal.rbegin();
  if (*itr == 'f' || *itr == 'F')
    literal = literal.substr(0, literal.length() - 1);
  input.str(literal);
  input >> d.floatValue;
  if (input.fail() == false && input.eof() == true)
    return FLOAT;

  input.clear();
  input.str(literal);
  input >> d.doubleValue;
  if (input.fail() == false && input.eof() == true)
    return DOUBLE;
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
    converter.convertFromInt(d.intValue);
    break;
  case FLOAT:
    converter.convertFromFloat(d.floatValue);
    break;
  case DOUBLE:
    converter.convertFromDouble(d.doubleValue);
    break;
  case PSEUDO_LITERAL:
    converter.convertPseudoLiteral(literal, d.isPseudoFloat);
    break;
  default:
    std::cout << "Conversion Not possible! Invalid input argument" << std::endl;
    break;
  }
}
