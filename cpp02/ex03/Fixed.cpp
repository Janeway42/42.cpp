#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//-----------Constructors & Destructor----------------

Fixed::Fixed(void)
{
	std::cout << "Default constructer called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int element)
{
	std::cout << "Int constructor called" << std::endl;
	_value = element << _bits;
}

Fixed ::Fixed(const float element)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)roundf(element * (1 << _bits));
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

//------------------Operators--------------------------

Fixed& Fixed::operator = (Fixed const &existing)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &existing)
		_value = existing.getRawBits();
	return (*this);
}

//---------------Comparation Operators--------------------

bool Fixed::operator < (const Fixed &existing) const
{
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

    temp.setRawBits((this->toFloat() * existing.toFloat()) * (1 << _bits));
	return (temp);
}

Fixed Fixed::operator / (const Fixed &existing) const
{
	Fixed temp;

    temp.setRawBits((this->toFloat() / existing.toFloat()) * (1 << _bits));
	return (temp);
}

//-----------Increment/Decrement Operators-------------

Fixed& Fixed::operator ++(void) // pre-increment
{
	this->setRawBits(_value + 1);
	return (*this);
}

Fixed Fixed::operator ++(int) // post-increment
{
	Fixed temp = *this;

    _value = _value + 1;
	return (temp);
}

Fixed& Fixed::operator --(void) // pre-increment
{
	this->setRawBits(_value - 1);
	return (*this);
}

Fixed Fixed::operator --(int) // post-increment
{
	Fixed temp = *this;

	_value = _value - 1;
	return (temp);
}

//----------------Static Functions--------------------

Fixed& Fixed::min(Fixed& one, Fixed &two)
{
	if (one <= two)
		return (one);
	return (two);
}

const Fixed& Fixed::min(const Fixed &one, const Fixed &two)
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

const Fixed& Fixed::max(const Fixed &one, const Fixed &two)
{
	if (one >= two)
		return (one);
	return (two);
}

//----------------Public Functions---------------------

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

//-------------Other Operators-----------------------

std::ostream & operator << (std::ostream &out, const Fixed &existing)
{
	out << existing.toFloat();
	return(out);
}