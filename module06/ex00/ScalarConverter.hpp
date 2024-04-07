#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

enum Type { CHAR, INT, FLOAT, DOUBLE, PSEUDO_LITERAL, UNKNOWN };

struct data {
  bool  isPseudoFloat;
  char charValue;
  long intValue;
  double floatValue;
  long double doubleValue;
};

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(const ScalarConverter &rhs);
  ~ScalarConverter();

  void convertFromChar(char c);
  void convertFromInt(long num);
  void convertFromFloat(double num);
  void convertFromDouble(long double num);
  void convertPseudoLiteral(std::string &literal, bool isFloat);
  Type checkType(std::string &input, data &d);

public:
  static void convert(const std::string &input);
};

#endif
