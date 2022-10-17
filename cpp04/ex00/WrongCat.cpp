#include "WrongCat.hpp"

//-------------Constructors &Destructors------------

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
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
    std::cout << this->type << ": Uaim Uaim!" << std::endl;
}
