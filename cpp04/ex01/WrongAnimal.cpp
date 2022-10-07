#include "WrongAnimal.hpp"
#include <iostream>

//-----------Constructors & Destructors--------------

WrongAnimal::WrongAnimal(void): type("no type")
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &existing)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = existing;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
//------------------Operators--------------------------

WrongAnimal& WrongAnimal::operator =(WrongAnimal const &existing)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &existing)
        this->type = existing.getType();
    return (*this);
}

//-------------Public Functions --------------------

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal here! Not even default animal sound for you!" << std::endl;
}
