#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
class AMateria;

class ICharacter
{
    private:
    	std::string _type;

    public:
    	ICharacter(void);
    	// ICharacter(std::string const &type);
    	ICharacter(const ICharacter &existing);        
    	virtual ~ICharacter(void);

        // virtual std::string const & getName()const = 0;
        virtual void equip(AMateria* m) = 0;
        // virtual void unequip(int idx) = 0;
        // virtual void use(int idx, ICharacter& target) = 0;

	    ICharacter& operator = (ICharacter const &existing);

        std::string getType(void)const;

};

#endif