#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(std::string type);
	~WrongCat(void);

	void makeSound();
};

#endif