#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;


public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	~WrongAnimal(void);

	std::string getType() const;
	void makeSound() const;

};

#endif