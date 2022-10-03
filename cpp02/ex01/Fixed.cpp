#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//-----------Constructors & Destructors-----------

Fixed ::Fixed(void)
{
	std::cout << "Default constructer called" << std::endl;
	_value = 0;
}

Fixed ::Fixed(const int element)
{
	std::cout << "Int constructor called" << std::endl;
	_value = element << _bits;
}

Fixed ::Fixed(const float element)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)roundf(element * (1 << _bits));
}

Fixed ::Fixed(const Fixed &existing)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = existing;
}

Fixed ::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

//----------Overload operators-------------------

Fixed& Fixed:: operator = (Fixed const &existing)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &existing)
		_value = existing.getRawBits();
	return (*this);
}

//-------------Public functions-----------------

int Fixed::getRawBits(void) const
{
	std::cout << "getRawbits member function called" << std:: endl;
	return(_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawbits member function called" << std:: endl;
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_value/(float)(1 << _bits));
}

int Fixed::toInt(void) const
{
	return ((int)(_value >> _bits));
}

//-------------Other Operators----------------------

std::ostream & operator << (std::ostream &out, const Fixed &existing)
{
	out << existing.toFloat();
	return(out);
}
