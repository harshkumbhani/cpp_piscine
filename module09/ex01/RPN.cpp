#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src) { (void)src; }

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
  (void)rhs;
  return *this;
}

operations RPN::checkOperator(char c) {
  switch (c) {
  case '+':
    return ADD;
  case '-':
    return SUBTRACT;
  case '*':
    return MULTIPLY;
  case '/':
    return DIVIDE;
  default:
    break;
  }
  return NOT_AN_OPERATOR;
}

float RPN::performOperation(float val1, float val2, operations operand) {
  float ret = 0;

  switch (operand) {
  case ADD:
    ret = val1 + val2;
    break;
  case SUBTRACT:
    ret = val1 - val2;
    break;
  case MULTIPLY:
    ret = val1 * val2;
    break;
  case DIVIDE:
    ret = val1 / val2;
    break;
  default:
    break;
  }
  return ret;
}

void RPN::parse(const std::string &input) {
  if (input.empty() == true ||
      input.find_first_not_of(" \t\n\r") == std::string::npos)
    throw RPN::EmptyInputString();
  if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
    throw RPN::UnknownCharInString();
}

void RPN::calculate(const std::string &input) {
  std::stack<float> rpn;
  std::istringstream ss(input);
  std::string token;
  size_t counter = 0; // to handle case when only one digit is present

  parse(input);
  while (ss >> token) {
    if (token.empty() == true)
      continue;
    if (token.size() > 1)
      throw RPN::FoundCharOfNotSize1();
    operations op = checkOperator(token[0]);

    if (op != NOT_AN_OPERATOR) {
      if (rpn.size() < 2)
        throw RPN::StringNotInStandardFormat();
      float val2 = rpn.top();
      rpn.pop();
      float val1 = rpn.top();
      rpn.pop();
      rpn.push(performOperation(val1, val2, op));
    } else {
      counter++;
      rpn.push(static_cast<float>(atof(token.c_str())));
    }
  }

  if (rpn.size() != 1 || counter == 1)
    throw RPN::StringNotInStandardFormat();
  std::cout << "Result: " << rpn.top() << std::endl;
}
