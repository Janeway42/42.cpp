#include "ICharacter.hpp"

//-----------Constructors & Destructors----------

ICharacter::ICharacter(void)
{
    std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &existing)
{
    std::cout << "ICharacter copy constructor called" << std::endl;
    *this = existing;
}

ICharacter::~ICharacter(void)
{
    std::cout << "ICharacter destructor called" << std::endl;
}
//----------------- Operators--------------------

ICharacter& ICharacter::operator =(ICharacter const &existing)
{
    std::cout << "ICharacter copy assignment operator called" << std::endl;
    if (this != &existing)
        this->_type = existing.getType();
    return (*this);
}

//-------------Public Functions------------------

std::string ICharacter::getType(void)const
{
    return (this->_type);
}
