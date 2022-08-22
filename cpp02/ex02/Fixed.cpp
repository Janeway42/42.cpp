#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//-----------Constructors & Destructor----------------

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

//------------------Operators--------------------------

Fixed& Fixed:: operator = (Fixed const &existing)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &existing)
		_value = existing.getRawBits();
	return (*this);
}

std::ostream & operator << (std::ostream &out, const Fixed &existing)
{
	out << existing.toFloat();
	return(out);
}

//---------------Comparation Operators--------------------

bool Fixed::operator < (const Fixed &existing) const
{
	// if (_value > existing.getRawBits())
	// 	return (1);
	// return (0);
	return (_value < existing.getRawBits());
}

bool Fixed::operator > (const Fixed &existing) const
{
	return (_value > existing.getRawBits());
}

bool Fixed::operator <= (const Fixed &existing) const
{
	return (_value <= existing.getRawBits());
}

bool Fixed::operator >= (const Fixed &existing) const
{
	return (_value >= existing.getRawBits());
}

bool Fixed::operator == (const Fixed &existing) const
{
	return (_value == existing.getRawBits());
}

bool Fixed::operator != (const Fixed &existing) const
{
	return (_value == existing.getRawBits());
}

//---------------Artimetic Operators----------------------

Fixed Fixed::operator + (const Fixed &existing) const
{
	Fixed temp;

	temp.setRawBits(_value + existing.getRawBits());
	return (temp);
}

Fixed Fixed::operator - (const Fixed &existing) const
{
	Fixed temp;

	temp.setRawBits(_value - existing.getRawBits());
	return (temp);
}

Fixed Fixed::operator * (const Fixed &existing) const
{
	Fixed temp; 

	temp.setRawBits(_value * existing.getRawBits());
	return (temp);  //Fractal?
}

Fixed Fixed::operator / (const Fixed &existing) const
{
	Fixed temp;

	temp.setRawBits(_value / existing.getRawBits());
	return (temp);  // Fractal??
}

//-----------Increment/Decrement Operators-------------

Fixed & Fixed::operator ++(void)
{
	this->setRawBits(_value + (1 << _bits));
	return (*this);
}

Fixed Fixed::operator ++(int)
{
	Fixed temp;

	temp.setRawBits(_value + (1 << _bits));
	return (temp);
}

Fixed & Fixed::operator --(void)
{
	this->setRawBits(_value - (1 << _bits));
	return (*this);
}

Fixed Fixed::operator --(int)
{
	Fixed temp;

	temp.setRawBits(_value - (1 << _bits));
	return (temp);
}

//----------------Static Functions--------------------

Fixed& Fixed::min(Fixed& one, Fixed &two)
{
	if (one <= two)
		return (one);
	return (two);
}

Fixed& Fixed::max(Fixed& one, Fixed &two)
{
	if (one >= two)
		return (one);
	return (two);
}

const Fixed &min(const Fixed &one, const Fixed &two)
{
	if (one <= two)
		return (one);
	return (two);
}

const Fixed &max(const Fixed &one, const Fixed &two)
{
	if (one >= two)
		return (one);
	return (two);
}

//----------------Other Functions---------------------

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