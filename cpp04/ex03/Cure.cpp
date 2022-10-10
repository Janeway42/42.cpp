#include "Cure.hpp"

//-----------Constructors & Destructors----------

Cure::Cure(void): _type("Cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &existing)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

//----------------- Operators--------------------

Cure& Cure::operator = (Cure const &existing)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	*this = existing;
}

//-------------Public Functions------------------

Cure* Cure::clone(void)const
{
	Cure* temp;

	return (temp);
}
