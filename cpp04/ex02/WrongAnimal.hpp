#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal(void);
    WrongAnimal(const WrongAnimal &existing);
	virtual ~WrongAnimal(void);

    WrongAnimal& operator = (WrongAnimal const &existing);

	std::string getType() const;
	virtual void makeSound() const;

};

#endif