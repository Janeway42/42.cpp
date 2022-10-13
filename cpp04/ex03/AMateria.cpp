#include "AMateria.hpp"

//-----------Constructors & Destructors----------

AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor called" << std::endl;
	this->_type = "no type";
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria type constructor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria &existing)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = existing;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

//----------------- Operators--------------------

AMateria& AMateria::operator= (AMateria const &existing)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &existing)
        this->_type = existing.getType();
    return (*this);
}
//-------------Public Functions------------------

void AMateria::use(ICharacter& target)
{
    if (this->getType() == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if (this->getType() == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    else
        std::cout << "Unknown type! Unable to dance for you!" << std::endl;
}

const std::string& AMateria::getType(void)const
{
	return (this->_type);
}

void AMateria::setType(std::string type)
{
    this->_type = type;
}