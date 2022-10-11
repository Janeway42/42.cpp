#include "ICharacter.hpp"

//-----------Constructors & Destructors----------

ICharacter::ICharacter(void):_name("no name")
{
    std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(std::string name):_name(name)
{
    std::cout << "ICharacter " << this->_name << " constructor called" << std::endl;
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
    // if (this != &existing)
    //     this->_type = existing.getType();
    return (*this);
}

//-------------Public Functions------------------

std::string const & ICharacter::getName(void)const
{
     return (this->_name);
}
