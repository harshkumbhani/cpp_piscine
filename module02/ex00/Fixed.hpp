#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

const std::string RESET = "\033[0m";
const std::string RED =  "\033[0;31m";
const std::string YELLOW = "\033[0;33m";
const std::string BLUE = "\033[0;34m";
const std::string MAGENTA = "\033[0;35m";
const std::string CYAN = "\033[0;36m";
const std::string GREEN = "\033[32m";

class Fixed {
private:
  int _fixedPointNumber;
  static const int _fractionalBit = 8;

public:
  Fixed();
  Fixed(Fixed const & src);
  Fixed &operator=(const Fixed &rhs);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
