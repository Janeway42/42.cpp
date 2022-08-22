#include "Cat.hpp"

//-------------Constructors &Destructors------------

// Cat::Cat(void)
// {
// 	std::cout << "Cat default constructor called" << std::endl;
// }

Cat::Cat (void): Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

//--------------Public Functions-------------------

