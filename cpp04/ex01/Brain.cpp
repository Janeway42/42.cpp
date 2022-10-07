#include "Brain.hpp"
#include <string>
#include <cstdlib>

//-------Constructors & Destructors --------

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;

	std::string randomSource = "0123456789";
	for (int i = 0; i < 100; i++)
		_ideas[i] = std::to_string(i) + "." + randomSource[rand() % randomSource.length()] + " ";
}

Brain::Brain(const Brain &existing)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = existing;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

//-----------Overload Operator--------------

Brain& Brain::operator = (Brain const &existing)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &existing)
    {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = existing._ideas[i];
    }
	return (*this);
}

//-----------Public Functions---------------

void Brain::printIdeas(void)
{
	for (int i = 0; i < 100; i++)
		std::cout << _ideas[i];
}