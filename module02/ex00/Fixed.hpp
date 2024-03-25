#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
	int	_fixedPointNumber;
	static const int	_fractionalBit = 8;

	public:
	Fixed();
	Fixed(Fixed const &);
	Fixed& operator=(const Fixed&);
	~Fixed();

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
