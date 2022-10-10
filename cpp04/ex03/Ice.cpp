#include "Ice.hpp"

//-----------Constructors & Destructors----------

Ice::Ice(void): _type("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &existing)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

//----------------- Operators--------------------

Ice& Ice::operator = (Ice const &existing)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	*this = existing;
}

//-------------Public Functions------------------

Ice* Ice::clone(void)const
{
	Ice* temp;

	return (temp);
}
