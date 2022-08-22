#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;


public:
	Animal(void);
	Animal(std::string type);
	~Animal(void);

	std::string getType() const;
	void makeSound() const;

};

#endif