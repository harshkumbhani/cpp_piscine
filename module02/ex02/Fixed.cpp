#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumber(0) {}

Fixed::Fixed(const int nbInt) : _fixedPointNumber(nbInt << _fractionalBit) {}

Fixed::Fixed(const float nbFloat)
    : _fixedPointNumber(
          static_cast<int>(roundf(nbFloat * (1 << _fractionalBit)))) {}

Fixed::Fixed(Fixed const &src) { *this = src; }

Fixed &Fixed::operator=(const Fixed &rhs) {
  if (this != &rhs)
    _fixedPointNumber = rhs.getRawBits();
  return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return _fixedPointNumber; }

void Fixed::setRawBits(const int raw) { _fixedPointNumber = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(_fixedPointNumber) / (1 << _fractionalBit);
}

int Fixed::toInt(void) const { return _fixedPointNumber >> _fractionalBit; }

std::ostream &operator<<(std::ostream &o, Fixed const &fixedObj) {
  o << fixedObj.toFloat();
  return o;
}

Fixed& Fixed::operator++() {
  _fixedPointNumber++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  _fixedPointNumber++;
  return temp;
}


Fixed& Fixed::operator--() {
  _fixedPointNumber--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  _fixedPointNumber--;
  return temp;
}

Fixed Fixed::operator+(Fixed const &rhs) const {
  return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const {
  return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs) const {
  return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const {
  return (Fixed(this->toFloat() / rhs.toFloat()));
}

bool  Fixed::operator>(Fixed const &rhs) const {
  return (this->getRawBits() > rhs.getRawBits());
}

bool  Fixed::operator>=(Fixed const &rhs) const {
  return (this->getRawBits() >= rhs.getRawBits());
}

bool  Fixed::operator<(Fixed const &rhs) const {
  return (this->getRawBits() < rhs.getRawBits());
}

bool  Fixed::operator<=(Fixed const &rhs) const {
  return (this->getRawBits() <= rhs.getRawBits());
}

bool  Fixed::operator==(Fixed const &rhs) const {
  return (this->getRawBits() == rhs.getRawBits());
}

bool  Fixed::operator!=(Fixed const &rhs) const {
  return (this->getRawBits() != rhs.getRawBits());
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs){
  return (lhs < rhs ? lhs : rhs);
}

const Fixed& Fixed::min(Fixed const & lhs, Fixed const &rhs){
  return (lhs < rhs ? lhs : rhs);
}
Fixed& Fixed::max(Fixed& lhs, Fixed& rhs){
  return (lhs > rhs ? lhs : rhs);
}
const Fixed& Fixed::max(Fixed const &lhs, Fixed const &rhs){
  return (lhs > rhs ? lhs : rhs);
}
