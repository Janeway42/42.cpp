#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    private:
    	std::string _type;

    public:
    	AMateria(void);
    	AMateria(std::string const &type);
    	AMateria(const AMateria &existing);
    	virtual ~AMateria(void);

	    AMateria& operator = (AMateria const &existing);

    	std::string const & getType() const; //Returns the materia type
    	void setType(std::string type);
        virtual AMateria* clone(void) const = 0;
    	// virtual void use(ICharacter& target);
};

#endif