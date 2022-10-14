#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include <ostream>

class Character: public ICharacter
{
    protected:
        std::string _name;
    	AMateria* _inventory[4];

    public:
    	Character(void);
    	Character(std::string name);
    	Character(const Character &existing);
    	~Character(void);

        Character& operator = (Character const &existing);        

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        std::string const & getName(void)const;
        int getInventorySlots(void)const;
        AMateria* getInventoryItem(int location)const;
        void printInventoryItemType(int location);

        int firstEmptySlot(void);

};

#endif