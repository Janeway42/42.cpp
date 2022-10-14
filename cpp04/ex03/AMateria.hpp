#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class ICharacter;
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
    	std::string _type;

    public:
    	AMateria(void);
    	AMateria(std::string const &type);
    	AMateria(const AMateria &existing);
    	virtual ~AMateria(void);

	    AMateria& operator = (AMateria const &existing);

    	std::string const & getType() const;
    	void setType(std::string type);
        
        virtual AMateria* clone(void) const = 0;
    	virtual void use(ICharacter& target);
};

#endif