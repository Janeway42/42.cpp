#include "WrongCat.hpp"

//-------------Constructors &Destructors------------

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "Cat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &existing)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = existing;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}
//------------------Operators--------------------------

WrongCat& WrongCat::operator = (WrongCat const &existing)
{
    std::cout << "WrongCat copy assignemnt operator called" << std::endl;
    if (this != &existing)
        this->type = existing.getType();
    return (*this);
}

//--------------Public Functions-------------------

void WrongCat::makeSound(void)const
{
    if (this->type.compare("WrongCat") == 0)
        std::cout << this->type << ": Uaim Uaim!" << std::endl;
    else
        std::cout << this->type << ": Say what?!" << std::endl;
}
