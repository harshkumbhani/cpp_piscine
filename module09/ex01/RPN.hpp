#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
private:
public:
  RPN();
  RPN(const RPN &src);
  ~RPN();

  RPN &operator=(const RPN &rhs);

  void calculate(const std::string &input);
};

#endif
