#include "Character.hpp"

//-----------Constructors & Destructors----------

Character::Character(void)
{
    std::cout << "Character default constructor called" << std::endl;
    this->_inventorySlots = 0;
}

Character::Character(const Character &existing)
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = existing;
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
}

//----------------- Operators--------------------

Character& Character::operator = (Character const &existing)
{
    std::cout << "Character copy assignemnt operator called" << std::endl;
    if (this != &existing)
    {
        for (int i = 0; i < 4; i++)
        {
            this->_inventory[i] = existing.getInventoryItem(i);
            i++;
        }
    }
    return (*this);
}

//-------------Public Functions------------------

AMateria* Character::getInventoryItem(int location)const
{
    return(this->_inventory[location]);
}

void Character::equip(AMateria* m)
{
    if (this->_inventorySlots < 3)  // unexisting Materia????
        this->_inventory[this->_inventorySlots] = m;
}
