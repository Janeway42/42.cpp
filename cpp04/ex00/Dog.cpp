#include "Dog.hpp"

//-----------Constructors & Destructors-----------

// Dog::Dog(void)
// {
// 	std::cout << "Dog default constructor called" << std::endl;
// }

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog denstructor called" << std::endl;
}

//---------Public Functions---------------------

