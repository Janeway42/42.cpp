#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter
{
    private:
    	AMateria* _inventory[4];
        int _inventorySlots;

    public:
    	Character(void);
    	// Character(std::string const &type);
    	Character(const Character &existing);
    	~Character(void);

        Character& operator = (Character const &existing);        

        AMateria* getInventoryItem(int location)const;
        void equip(AMateria* m);

};

#endif