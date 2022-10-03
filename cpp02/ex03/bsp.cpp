#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
    std::cout << "inside bsp ------------------------------------------\n";
    float aX = (a.getX()).toFloat();
    float aY = (a.getY()).toFloat();
	std::cout << std::endl;

    float bX = (b.getX()).toFloat();
    float bY = (b.getY()).toFloat();
	std::cout << std::endl;

    float cX = (c.getX()).toFloat();
    float cY = (c.getY()).toFloat();
	std::cout << std::endl;

    float pX = (p.getX()).toFloat();
    float pY = (p.getY()).toFloat();
	std::cout << std::endl;

    float Area = 0.5 * (((-1 * bY) * cX) + aY * ((-1 * bX + cX) + aX * (bY - cY) + bX * cY));

    float s = 1/(2*Area) * ((aY * cX) - (aX * cY) + ((cY - aY) * pX) + ((aX - cY) * pY));
    float t = 1/(2*Area) * ((aX * bY) - (aY * bX) + (aY - bY) * pX + (bX - aX) * pY);

    if (s > 0 && t > 0 && (1 - s - t) > 0)
        return (true);
    return (false);
}
