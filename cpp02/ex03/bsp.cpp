#include "Point.hpp"

Fixed tringleArea(Point const &A, Point const &B,Point const &C)
{
	Fixed area = (	  A.getX() * (B.getY() - C.getY()  )
					+ B.getX() * (C.getY() - A.getY())
					+ C.getX() * (A.getY() - B.getY()));

  	area = area / Fixed(2);

	if(area < 0)
		area = area * Fixed(-1);
	return area;

}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaPoint = tringleArea(a,b,c);
	Fixed areaA = tringleArea(point,b,c);
	Fixed areaB = tringleArea(a,point,c);
	Fixed areaC = tringleArea(a,b,point);

	if(areaPoint==0)
	{
		std::cout << "Triangle is a line" << std::endl;
		return false;
	}
	if(areaA==0 || areaB==0 || areaC==0)
		return false;
	return(areaPoint == (areaA+areaB+areaC) ? true : false);
}