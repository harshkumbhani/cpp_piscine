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

std::list<std::string> split(const std::string &input) {
  std::list<std::string> ret;

  std::istringstream ss(input);
  std::string str;

  while (std::getline(ss, str, ' ')) {
    if (str.empty() == true)
      continue;
    if (str.size() != 1)
      throw RPN::FoundCharOfNotSize1();
    ret.push_back(str);
  }
  return ret;
}

void RPN::parse(const std::string &input) {
  if (input.empty() == true ||
      input.find_first_not_of(" \t\n\r") == std::string::npos)
    throw RPN::EmptyInputString();
  if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
    throw RPN::UnknownCharInString();

  size_t counter = 0;
  std::list<std::string> list = split(input);

  if (list.size() < 3)
    throw RPN::StringNotInStandardFormat();
  std::list<std::string>::iterator it;
  for (it = list.begin(); it != list.end(); it++) {
    if (it->find_first_of("+-/*") != std::string::npos && counter >= 2) {
      counter -= 2; // Similar to Popping to elements from the stack
      counter += 1; // Similar to pushing to pushing the result on stack
    } else {
      counter += 1;
    }
  }
  if (counter != 1)
    throw RPN::StringNotInStandardFormat();
}

void RPN::calculate(const std::string &input) {
  std::stack<float> rpn;
  std::string str;
  operations expression;
  float val1;
  float val2;

  parse(input);
  std::stringstream ss(input);
  while (std::getline(ss, str, ' ')) {
    if (str.empty() == true)
      continue;
    expression = checkOperator(str[0]);
    if (expression == NOT_AN_OPERATOR)
      rpn.push(static_cast<float>(str[0] - '0'));
    else {
      val2 = rpn.top();
      rpn.pop();
      val1 = rpn.top();
      rpn.pop();
      float toPush = performOperation(val1, val2, expression);
      rpn.push(toPush);
    }
  }
  std::cout << "Result: " << rpn.top() << std::endl;
}
