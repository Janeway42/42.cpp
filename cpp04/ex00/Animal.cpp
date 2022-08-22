#include "Animal.hpp"
#include <iostream>

//-----------Constructors & Destructors--------------

Animal::Animal(void)
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

//-------------Public Functions --------------------

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	if (this->type.compare("Dog") == 0)
		std::cout << this->type << ": Woof Woof!" << std::endl;
	if (this->type.compare("Cat") == 0)
		std::cout << this->type << ": Miau Miau!" << std::endl;
}

