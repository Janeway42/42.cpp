#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(const Animal &existing);
	virtual ~Animal(void);

	Animal& operator = (Animal const &existing);

	std::string getType() const;
	virtual void makeSound() const = 0;

};

#endif