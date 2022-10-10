#include "Ice.hpp"

//-----------Constructors & Destructors----------

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &existing)
{
	std::cout << "Ice copy constructor called" << std::endl;
    *this = existing;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

//----------------- Operators--------------------

Ice& Ice::operator = (Ice const &existing)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &existing)
        setType(existing.getType());
    return (*this);
}

//-------------Public Functions------------------

AMateria* Ice::clone(void)const
{
	AMateria* temp = new Ice();

	return (temp);
}
