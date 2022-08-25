#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain* _greyCells;

public:
	Cat(void);
	Cat(std::string type);
	Cat(const Cat &existing);
	~Cat(void);

	Cat& operator = (Cat const &existing);

	void makeSound();
	void printCatIdeas(void);

};

#endif