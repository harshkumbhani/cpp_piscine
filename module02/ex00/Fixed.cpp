#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumber(0) {
  std::cout << GREEN << "⚙️  Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(Fixed const &src) {
  std::cout << YELLOW << "📋 Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
  std::cout << BLUE << "➡️  Copy assignment operator called" << RESET << std::endl;
  if (this != &rhs)
    _fixedPointNumber = rhs.getRawBits();
  return *this;
}

Fixed::~Fixed() { 
	std::cout << RED << "💥 Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const {
  std::cout << MAGENTA << "🔍 getRawbits member function called" << RESET << std::endl;
  return _fixedPointNumber;
}

void Fixed::setRawBits(const int raw) {
  std::cout << MAGENTA << "✏️  setRawbits memeber function called" << RESET <<  std::endl;
  _fixedPointNumber = raw;
}
