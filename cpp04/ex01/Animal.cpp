#include "Animal.hpp"
#include <iostream>

//-----------Constructors & Destructors--------------

Animal::Animal(void)
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << "Animal type constructor" << std::endl;
	this->_type = type;
}

Animal::Animal(const Animal &existing)
{
	std::cout << "Animal copy constructor called" << std::endl;
	// this->_type = existing.getType();
	*this = existing;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

//-----------Overload Operator--------------

Animal& Animal::operator = (Animal const &existing)
{
	std::cout << "Animal copy assignment operator called" << std::endl;

	if (this != &existing)
		this->_type = existing._type;
	return (*this);
}

//-------------Public Functions --------------------

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	if (this->_type.compare("Dog") == 0)
		std::cout << this->_type << ": Woof Woof!" << std::endl;
	else if (this->_type.compare("Cat") == 0)
		std::cout << this->_type << ": Miau Miau!" << std::endl;
	else
		std::cout << "No comment!" << std::endl;
}

