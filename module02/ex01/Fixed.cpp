#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumber(0) {
  std::cout << GREEN << "⚙️  Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int nbInt) : _fixedPointNumber(nbInt << _fractionalBit) {
std::cout << CYAN << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(const float nbFloat)
    : _fixedPointNumber(
          static_cast<int>(roundf(nbFloat * (1 << _fractionalBit)))) {
  std::cout << MAGENTA << "Float constructor called" << RESET << std::endl;
}

Fixed::Fixed(Fixed const &src) {
  std::cout << YELLOW << "📋 Copy constructor called" << RESET << std::endl;
  *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
  std::cout << BLUE << "➡️  Copy assignment operator called" << RESET
            << std::endl;
  if (this != &rhs)
    _fixedPointNumber = rhs.getRawBits();
  return *this;
}

Fixed::~Fixed() {
  std::cout << RED << "💥 Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const {
  return _fixedPointNumber;
}

void Fixed::setRawBits(const int raw) {
  _fixedPointNumber = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(_fixedPointNumber) / (1 << _fractionalBit);
}

int Fixed::toInt(void) const {
  return _fixedPointNumber >> _fractionalBit;
}

std::ostream& operator<<(std::ostream &o, Fixed const &fixedObj) {
  o << fixedObj.toFloat();
  return o;
}
