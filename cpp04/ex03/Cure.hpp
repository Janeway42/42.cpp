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

		AMateria* clone(void) const;
};

#endif