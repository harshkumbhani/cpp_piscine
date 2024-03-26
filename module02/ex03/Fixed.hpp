#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <iomanip>

class Fixed {
private:
  int _fixedPointNumber;
  static const int _fractionalBit = 8;

public:
  Fixed();
  Fixed(const int nbInt);
  Fixed(const float nbFloat);
  Fixed(Fixed const & src);
  Fixed &operator=(const Fixed &rhs);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  // Increment / Decrement operators
  Fixed&  operator++(); // preincrement
  Fixed  operator++(int); // postincrement
  Fixed&  operator--(); // predecrement
  Fixed operator--(int); //postdecrement

  // Arithmetic operators
  Fixed operator+(Fixed const &rhs) const;
  Fixed operator-(Fixed const &rhs) const;
  Fixed operator*(Fixed const &rhs) const;
  Fixed operator/(Fixed const &rhs) const;

  // Comparison operators
  bool operator>(Fixed const &rhs) const;
  bool operator>=(Fixed const &rhs) const;
  bool operator<(Fixed const &rhs) const;
  bool operator<=(Fixed const &rhs) const;
  bool operator==(Fixed const &rhs) const;
  bool operator!=(Fixed const &rhs) const;

  // Min / Max methods
  static Fixed& min(Fixed& lhs, Fixed& rhs);
  static const Fixed& min(Fixed const &lhs, Fixed const &rhs);
  static Fixed& max(Fixed& lhs, Fixed& rhs);
  static const Fixed& max(Fixed const &lhs, Fixed const &rhs);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixedObj);

#endif
