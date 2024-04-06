#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
private:
  enum Type { CHAR, INT, FLOAT, DOUBLE, PSEUDO_LITERAL, UNKNOWN };

  ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(const ScalarConverter &rhs);
  ~ScalarConverter();

  void convertFromChar(char c);
  void convertFromInt(int num);
  void convertFromFloat(float num);
  void convertFromDouble(float num);
  void printConvertedValues(Type type);
  Type checkType(std::string &input);

public:
  static void convert(const std::string &input);
};

#endif
