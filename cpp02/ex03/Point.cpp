#include "Point.hpp"
#include <iostream>

//-----------Constructors & Destructor----------------

Point::Point(void): _x(0), _y(0)
{
	std::cout << "Point default constructer called" << std::endl;
}

Point::Point(float const a, float const b): _x(a), _y(b)
{
    std::cout << "Point float constructor called" << std::endl;
}

Point::Point(const Point &existing)
{
    std::cout << "Point copy constructor called" << std::endl;
    *this = existing;
}

Point::~Point(void)
{
    std::cout << "Point destructor called" << std::endl;
}

//------------------Operators--------------------------

Point& Point::operator = (Point const &existing)
{
    if (this != &existing)
    {
        Fixed *tempX;
        tempX = (Fixed *)&this->_x;
        *tempX = existing.getX();

        Fixed *tempY;
        tempY = (Fixed *)&this->_y;
        *tempY = existing.getY();
    }
    return (*this);
}

//----------------Public Functions---------------------

Fixed Point::getX(void)const 
{
    return (this->_x);
}

Fixed Point::getY(void)const
{
    return (this->_y);
}
