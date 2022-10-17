#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat: public WrongAnimal
{
	private:
		Brain* _greyCells;

	public:
		WrongCat(void);
   		WrongCat(const WrongCat &existing);
		~WrongCat(void);

    	WrongCat& operator = (WrongCat const &existing);

		void makeSound(void)const;
};

#endif