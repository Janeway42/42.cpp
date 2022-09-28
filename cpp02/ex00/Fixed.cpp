#include "Fixed.hpp"
#include <iostream>

//-----------Constructors & Destructors-----------

Fixed::Fixed(void)
{
	_value = 0;
	std::cout << "Default constructer called" << std::endl;
}

Fixed::Fixed(const Fixed &existing)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = existing;
}

Fixed::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

//----------Overload operators-------------------

Fixed& Fixed::operator = (Fixed const &existing)
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
