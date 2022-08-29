#include "Dog.hpp"

//-----------Constructors & Destructors-----------

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_greyCells = new Brain();
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog type constructor called" << std::endl;
	_greyCells = new Brain();
}

Dog::Dog(const Dog &existing)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = existing.getType();
	this->_greyCells = new Brain(*(existing._greyCells));
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete (_greyCells);
}

//-----------Overload Operator--------------

Dog& Dog::operator = (Dog const &existing)
{
	std::cout << "Dog copy assignment operator called" << std::endl;

	if (this != &existing)
		*this->_greyCells = *existing._greyCells;
	return (*this);
}

//---------Public Functions---------------------

void Dog::makeSound(void)
{
	if (this->_type.compare("Dog") == 0)
		std::cout << this->_type << ": Woof Woof!" << std::endl;
	else
		std::cout << "No comment!" << std::endl;
}

void Dog::printDogIdeas(void)
{
	this->_greyCells->printIdeas();
}