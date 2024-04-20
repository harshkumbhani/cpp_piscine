#ifndef RPN_HPP
#define RPN_HPP

#include <stdlib.h>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";

enum operations { ADD, SUBTRACT, MULTIPLY, DIVIDE, NOT_AN_OPERATOR };

class RPN {
private:
  operations checkOperator(char c);
  float performOperation(float val1, float val2, operations operand);

public:
  RPN();
  RPN(const RPN &src);
  ~RPN();

  RPN &operator=(const RPN &rhs);

  void parse(const std::string &input);
  void calculate(const std::string &input);

  class EmptyInputString : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Parsing: String is empty";
    }
  };

  class UnknownCharInString : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Parsing: String contains unknown characters";
    }
  };

  class StringNotInStandardFormat : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Parsing: String not in Standard RPN format";
    }
  };

  class FoundCharOfNotSize1 : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Parsing: String container characters of size not equal to 1 :(";
    }
  };
};

#endif
