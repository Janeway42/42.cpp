#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
class AMateria;

class ICharacter
{
    private:

    protected:
        std::string _name;

    public:
    	ICharacter(void);
        ICharacter(std::string name);
    	ICharacter(const ICharacter &existing);        
    	virtual ~ICharacter(void);

	    ICharacter& operator = (ICharacter const &existing);

        virtual std::string const & getName()const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif