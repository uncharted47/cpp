#include "Point.hpp"

Point::Point(void)
{
}
Point const &Point::operator=(Point const &rhs)
{
	(void)rhs;
	return (*this);
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
}

Point::Point(Point const &copy) : _x(copy._x), _y(copy._y)
{
	*this = copy;
}

Point::~Point(void)
{
}

Fixed Point::getY(void) const
{
	return(this->_y);
}


Fixed Point::getX(void) const
{
	return(this->_x);
}





