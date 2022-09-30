#include "Point.hpp"
#include <iostream>

//-----------Constructors & Destructor----------------

Point::Point(void)
{
	std::cout << "Point default constructer called" << std::endl;
    Fixed const _x(0);
    Fixed const _y(0);
}

Point::Point(float const a, float const b)
{
    std::cout << "Point float constructor called" << std::endl;
    Fixed const _x(a);
    Fixed const _y(b);
    std::cout << _x << std::endl;
    std::cout << _y << std::endl;

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