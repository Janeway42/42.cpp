#include "WrongAnimal.hpp"
#include <iostream>

//-----------Constructors & Destructors--------------

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

//-------------Public Functions --------------------

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::makeSound(void) const
{
	if (this->type.compare("Dog") == 0)
		std::cout << this->type << ": foow foow!" << std::endl;
	if (this->type.compare("WrongCat") == 0)
		std::cout << this->type << ": uaim uaim!" << std::endl;
}

