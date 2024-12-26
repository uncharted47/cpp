#include "Fixed.hpp"

Fixed::Fixed(void) {
	this->_fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed const	&Fixed::operator = (Fixed const &obj)
{
	this->_fixedPointValue = obj.getRawBits();
	std::cout << "Assignation operator called" << std::endl;
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
}