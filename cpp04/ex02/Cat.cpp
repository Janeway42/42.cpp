#include "Cat.hpp"
#include <string.h>

//-------------Constructors &Destructors------------

Cat::Cat (void): Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	_greyCells = new Brain();
}

Cat::Cat (std::string type): Animal(type)
{
	std::cout << "Cat type constructor called" << std::endl;
	_greyCells = new Brain();
}

Cat::Cat(const Cat &existing)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = existing.getType();
	this->_greyCells = new Brain(*(existing._greyCells));
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
		*this->_greyCells = *existing._greyCells;
	return (*this);
}

//--------------Public Functions-------------------

void Cat::makeSound(void)
{
	if (this->_type.compare("Cat") == 0)
		std::cout << this->_type << ": Miau Miau!" << std::endl;
	else
		std::cout << "No comment!" << std::endl;
}

void Cat::printCatIdeas(void)
{
	this->_greyCells->printIdeas();
}