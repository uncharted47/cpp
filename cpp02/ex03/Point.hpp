#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"
#include <iostream>
#include <stdio.h>

class Point
{
	private :
		Fixed const _x;
		Fixed const _y;
	public :
		Point(void);
		Point(Fixed const x, Fixed const y);
		Point(Point const &copy);
		~Point(void);
		Fixed getX(void) const;
		Fixed getY(void) const;
		Point const &operator = (Point const &rhs);
		Fixed calculateArea(Point const a, Point const b, Point const c);
		bool bsp( Point const a, Point const b, Point const c, Point const point);

};
Fixed tringleArea(Point const &A, Point const &B,Point const &C);
#endif