#include "Dog.hpp"

//-----------Constructors & Destructors-----------

Dog::Dog(void): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &existing)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = existing;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

//------------------Operators--------------------------

Dog& Dog::operator = (Dog const &existing)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &existing)
        this->type = existing.getType();
    return (*this);
}

//---------Public Functions---------------------

void Dog::makeSound(void)const
{
    if (this->type.compare("Dog") == 0)
        std::cout << this->type << ": Wof Wof!" << std::endl;
    else
        std::cout << this->type << ": Say what?!" << std::endl;
}