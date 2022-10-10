#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
	private: 

	std::string _type;

	public: 
		Ice(void);
		Ice(const Ice &existing);
		~Ice(void);

		Ice& operator = (Ice const &existing);

		Ice* clone(void) const;

};

#endif