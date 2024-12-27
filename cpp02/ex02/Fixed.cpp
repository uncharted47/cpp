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

Fixed Fixed::operator - (Fixed const &obj) const
{
	return(Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator+(Fixed const &obj)
{
	return(Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator*(Fixed const &obj)
{
	return(Fixed(this->toFloat() * obj.toFloat()));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return(a.toFloat() < b.toFloat() ? a : b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	return(a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return(a.toFloat() > b.toFloat() ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return(a.getRawBits() > b.getRawBits()) ? a : b;
}

bool Fixed::operator>(Fixed const &obj)
{
	return(this->_fixedPointValue > obj.getRawBits());
}

bool Fixed::operator<(Fixed const &obj)
{
	return(this->_fixedPointValue < obj.getRawBits());
}

bool Fixed::operator>=(Fixed const &obj)
{
	return(this->_fixedPointValue >= obj.getRawBits());
}

bool Fixed::operator<=(Fixed const &obj)
{
	return(this->_fixedPointValue <= obj.getRawBits());
}

bool Fixed::operator==(Fixed const &obj)
{
	return(this->_fixedPointValue == obj.getRawBits());
}

bool Fixed::operator!=(Fixed const &obj)
{
	return(this->_fixedPointValue != obj.getRawBits());
}

Fixed Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return(tmp);
}


Fixed Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue--;
	return(tmp);
}
