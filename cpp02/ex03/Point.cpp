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
}

Point::Point(const Point &existing)
{
    std::cout << "Point copy constructor called" << std::endl;
    *this = existing;
}

//------------------Operators--------------------------

Point& Point::operator = (Point const &existing)
{
    if (this != &existing)
    {
       this->_x = existing.getX();
    }
    return (*this);
}

//----------------Public Functions---------------------

Fixed& const Point::getX(void)const
{
    return (this->_x);
}
