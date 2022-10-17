#include "Cat.hpp"
#include <string.h>

//-------------Constructors &Destructors------------

Cat::Cat (void): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
	_greyCells = new Brain();
}

Cat::Cat(const Cat &existing)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_greyCells = new Brain();
	*this = existing;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete (_greyCells);
}

//-----------Overload Operator--------------

Cat& Cat::operator = (Cat const &existing)
{
	std::cout << "Cat copy assignment operator called" << std::endl;

	if (this != &existing)
    {
        this->type = existing.getType();
		*this->_greyCells = *existing._greyCells;
    }
	return (*this);
}

//--------------Public Functions-------------------

void Cat::makeSound(void)const
{
    std::cout << this->type << ": Miau Miau!" << std::endl;
}

void Cat::printCatIdeas(void)
{
	this->_greyCells->printIdeas();
}
