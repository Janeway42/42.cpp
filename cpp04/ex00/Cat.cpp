#include "Cat.hpp"

//-------------Constructors &Destructors------------

Cat::Cat(void): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &existing)
{
    std::cout << "Cat copy constructor called" <<std::endl;
    *this = existing;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}
//------------------Operators--------------------------

Cat& Cat::operator =(Cat const &existing)
{
    if (this != &existing)
        this->type = existing.getType();
    return (*this);
}

//--------------Public Functions-------------------

void Cat::makeSound(void)const
{
    std::cout << this->type << ": Miau Miau!" << std::endl;
}
