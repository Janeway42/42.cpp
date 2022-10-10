#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria
{
	private: 

	std::string _type;

	public: 
		Cure(void);
		Cure(const Cure &existing);
		~Cure(void);

		Cure& operator = (Cure const &existing);

		Cure* clone(void) const;

};

#endif