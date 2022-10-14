#include "Character.hpp"

//-----------Constructors & Destructors----------

Character::Character(void)
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(std::string name):_name(name)
{
    std::cout << "Character -" << this->_name << "- constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(const Character &existing)
{
    std::cout << "Character copy constructor called" << std::endl;
    this->_name = existing._name;
    for (int i = 0; i < 4; i++)
    {
        if (existing._inventory[i])
            this->_inventory[i] = existing._inventory[i];
        else
            this->_inventory[i] = NULL;
    }
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] != NULL)
        {
            for (int j = i + 1; j < 4; j++)
                if (this->_inventory[i] == this->_inventory[j])
                    this->_inventory[j] = NULL;
            delete(this->_inventory[i]);
            this->_inventory[i] = NULL;
        }
    }
}

//----------------- Operators--------------------

Character& Character::operator = (Character const &existing)
{
    std::cout << "Character copy assignemnt operator called" << std::endl;
    if (this != &existing)
    {
        for (int i = 0; i < 4; i++)
        {
            delete(this->_inventory[i]);
            this->_inventory[i] = NULL;
            this->_inventory[i] = existing.getInventoryItem(i);
            i++;
        }
        this->_name = existing._name;
    }
    return (*this);
}

//-------------Get Public Functions------------------

std::string const & Character::getName(void)const
{
    return (this->_name);
}

AMateria* Character::getInventoryItem(int location)const
{
    if (location < 0 || location > 3)
        std::cout << "Character inventory index request is out of range" << std::endl;
    else
        return(this->_inventory[location]); 
    return (NULL);
}

//-------------Other Public Functions------------------

void Character::equip(AMateria* m)
{
    if (m)
    {
        int slot;
        slot = this->firstEmptySlot();
        if (slot < 4)
            this->_inventory[slot] = m;
        else
            std::cout << "Character equip: Full! No more free slots." << std::endl; 
    }
    else
        std::cout << "Character equip: Unavailable AMateria input" << std::endl;
}

void Character::unequip(int indx)
{
    if (this->firstEmptySlot() == 0)
        std::cout << "Character inventory is empty. Go do some shopping!" << std::endl;
    else if (indx > -1 && indx < 4)
    {
        if (this->_inventory[indx] == NULL)
            std::cout << "Character inventory slot already empty" << std::endl;
        else
        {
            this->_inventory[indx] = NULL;
            std::cout << "Character inventory slot " << indx << " is now NULL" << std::endl;
        }
    }
    else
        std::cout << "Index out of range. Unable to unequip inventory item" << std::endl;
}

void Character::use(int indx, ICharacter& target)
{
    if (indx < 0 || indx > 3)
        std::cout << "Character use: Input index out of range" << std::endl;
    else
    {
        if (this->getInventoryItem(indx) != NULL)
            this->getInventoryItem(indx)->use(target);
        else
            std::cout << "Character inventory slot empty. Unable to perform -use-" << std::endl;
    }
}

int Character::firstEmptySlot(void)
{
    int i = 0;
    for (i; i < 4; i++)
    {
        if (this->getInventoryItem(i) == NULL)
            return (i);
    }
    return (4);
}