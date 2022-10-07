#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog(void);
    Dog(std::string type);
    Dog(const Dog &existing);
	~Dog(void);

    Dog& operator = (Dog const &existing);

	void makeSound(void)const;
};

#endif