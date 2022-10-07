#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat(void);
    WrongCat(const WrongCat &existing);
	~WrongCat(void);

    WrongCat& operator = (WrongCat const &existing);

	void makeSound(void)const;
};

#endif