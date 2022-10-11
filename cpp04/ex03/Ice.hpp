#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
	private: 

	public: 
		Ice(void);
		Ice(const Ice &existing);
		~Ice(void);

		Ice& operator = (Ice const &existing);

		AMateria* clone(void) const;
    	// void use(ICharacter& target);
};

#endif