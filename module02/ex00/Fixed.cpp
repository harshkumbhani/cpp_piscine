#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) : _fixedPointNumber(copy._fixedPointNumber){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_fixedPointNumber = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawbits member function called" << std::endl;
	return _fixedPointNumber;
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawbits memeber function called" << std::endl;
	_fixedPointNumber = raw;
}
