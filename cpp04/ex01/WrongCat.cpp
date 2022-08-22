#include "WrongCat.hpp"

//-------------Constructors &Destructors------------

// Cat::Cat(void)
// {
// 	std::cout << "Cat default constructor called" << std::endl;
// }

WrongCat::WrongCat (void): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

//--------------Public Functions-------------------

