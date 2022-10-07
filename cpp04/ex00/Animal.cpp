#include "Animal.hpp"
#include <iostream>

//-----------Constructors & Destructors--------------

Animal::Animal(void): type("no type")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal &existing)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = existing;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

//------------------Operators--------------------------

Animal&  Animal::operator =(Animal const &existing)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &existing)
        type = existing.getType();
    return (*this);
}

//-------------Public Functions --------------------

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal: Default animal sound!" << std::endl;
}
