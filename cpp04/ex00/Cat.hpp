#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat(void);
    Cat(const Cat &existing);
	~Cat(void);

    Cat& operator = (Cat const &existing);

	void makeSound(void)const;
};

#endif