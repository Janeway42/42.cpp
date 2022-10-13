#include "Cure.hpp"

//-----------Constructors & Destructors----------

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &existing)
{
	std::cout << "Cure copy constructor called" << std::endl;
    *this = existing;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

//----------------- Operators--------------------

Cure& Cure::operator = (Cure const &existing)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &existing)
        setType(existing.getType());
    return (*this);
}

//-------------Public Functions------------------

AMateria* Cure::clone(void)const
{
	AMateria* temp = new Cure();

	return (temp);
}
