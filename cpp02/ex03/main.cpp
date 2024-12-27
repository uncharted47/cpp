#include "Point.hpp"


int main( void ) {
Point a(0, 0);
Point b(20, 0);
Point c(10, 30);
Point point1(10, 15);
Point point2(50, 50);

std::cout << "Triangle: A(" << a.getX() << ", " << a.getY() << ") B(" << b.getX() << ", " << b.getY() << ") C(" << c.getX() << ", " << c.getY() << ")" << std::endl;

// Test point inside the triangle
std::cout << "Point1: (" << point1.getX() << ", " << point1.getY() << ")" << std::endl;
point1.bsp(a, b, c, point1) == true ? std::cout << "Point is in the triangle" << std::endl : std::cout << "Point is not in the triangle" << std::endl;
// Expected result: Point is in the triangle

// Test point outside the triangle
std::cout << "Point2: (" << point2.getX() << ", " << point2.getY() << ")" << std::endl;
point2.bsp(a, b, c, point2) == true ? std::cout << "Point is in the triangle" << std::endl : std::cout << "Point is not in the triangle" << std::endl;
// Expected result: Point is not in the triangle
}