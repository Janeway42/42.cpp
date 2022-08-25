#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain* _greyCells;

public:
	Dog(void);
	Dog(std::string type);
	Dog(const Dog &existing);
	~Dog(void);

	Dog& operator = (Dog const &existing);

	void makeSound();
	void printDogIdeas(void);
};

#endif