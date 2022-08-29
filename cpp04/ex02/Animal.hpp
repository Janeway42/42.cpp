#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &existing);
	virtual ~Animal(void);

	Animal& operator = (Animal const &existing);

	std::string getType() const;
	virtual void makeSound() = 0;

};

#endif