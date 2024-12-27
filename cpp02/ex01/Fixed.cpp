#include "Fixed.hpp"

Fixed::Fixed(void) {
	this->_fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * ( 1 << this->_fractionalBits));
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = copy.getRawBits();
	*this = copy;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed const	&Fixed::operator = (Fixed const &obj)
{
	this->_fixedPointValue = obj.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
}

int Fixed::toInt( void ) const
{
	return(this->_fixedPointValue >> this->_fractionalBits);
}


float Fixed::toFloat(void) const
{
	return(((float)this->_fixedPointValue / (1 << this->_fractionalBits)) );
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

