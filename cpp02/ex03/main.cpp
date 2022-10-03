#include <iostream>
#include <string.h>
#include "Fixed.hpp"
#include "Point.hpp"

void printValues(Point X)
{
    std::cout << "._x: " << std::endl;
    std::cout << X.getX() << std::endl;
    std::cout << "._y: " << std::endl;
    std::cout << X.getY() << std::endl;
	std::cout << std::endl;
}

void verifyCopy(Point A, Point B)
{
    A = B;
	std::cout << std::endl;
    
    std::cout << "------ print A values again -------\n";
    printValues(A);
	std::cout << std::endl;
}

void triangleLocation(Point& a, Point& b, Point& c, Point& p)
{
    if (bsp(a, b, c, p) == 1)
        std::cout << "======= point is inside the triangle =======\n";
    else
        std::cout << "======= point is on/outside the triangle =======\n";
	std::cout << std::endl;
}

int main (void)
{
    Point A(1, 1);
    Point B(10 , 1);
    Point C(9, 10);
    Point point(9, 2);
	std::cout << std::endl;

    std::cout << "------- print A values --------\n";
    printValues(A);
	std::cout << std::endl;

    std::cout << "------- print B values --------\n";
    printValues(B);
	std::cout << std::endl;

    std::cout << "------- print C values --------\n";
    printValues(C);
	std::cout << std::endl;

    std::cout << "------- print point values -------\n";
    printValues(point);
	std::cout << std::endl;

    std::cout << "----------- A = B -------------\n";
    verifyCopy(A, B);
	std::cout << std::endl;

    std::cout << "--------triagnle calculation: -------------------" << std::endl;
    triangleLocation(A, B, C, point);
	std::cout << std::endl;

	return (0);
}
