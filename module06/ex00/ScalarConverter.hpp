#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

enum Type { CHAR, INT, FLOAT, DOUBLE, PSEUDO_LITERAL, UNKNOWN };

struct data {
  char charValue;
  int intValue;
  float floatValue;
  double doubleValue;
};

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(const ScalarConverter &rhs);
  ~ScalarConverter();

  void convertFromChar(char c);
  void convertFromInt(int num);
  void convertFromFloat(float num);
  void convertFromDouble(float num);
  void printConvertedValues(Type type);
  Type checkType(std::string &input, data &d);

public:
  static void convert(const std::string &input);
};

#endif
