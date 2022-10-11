#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria
{
	private: 

	public: 
		Cure(void);
		Cure(const Cure &existing);
		~Cure(void);

		Cure& operator = (Cure const &existing);

		Cure* clone(void) const;
    	// void use(ICharacter& target);
};

#endif