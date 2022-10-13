#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
class AMateria;

class ICharacter
{
    public:
    	// ICharacter(void);
        // ICharacter(std::string name);
    	// ICharacter(const ICharacter &existing);    
	    // ICharacter& operator = (ICharacter const &existing);

        virtual AMateria* getInventoryItem(int location)const = 0;  /// but there is no inventory????

    	virtual ~ICharacter(){}
        virtual std::string const & getName()const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif