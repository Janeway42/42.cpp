#include "Character.hpp"

//-----------Constructors & Destructors----------

Character::Character(void)
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    this->_inventorySlots = 0;
}

Character::Character(std::string name): ICharacter(name)
{
    printf("test\n");
    std::cout << "Character " << this->_name << " constructor called" << std::endl;

}

Character::Character(const Character &existing)
{
    std::cout << "Character copy constructor called" << std::endl;
    // Character* temp = new Character();  // deep copy  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    *this = existing;
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        delete(this->_inventory[i]);
}

//----------------- Operators--------------------

Character& Character::operator = (Character const &existing)
{
    std::cout << "Character copy assignemnt operator called" << std::endl;  // deep copy
    if (this != &existing)
    {
        for (int i = 0; i < 4; i++)
        {
            delete(this->_inventory[i]);
            this->_inventory[i] = NULL;
            this->_inventory[i] = existing.getInventoryItem(i);
            i++;
        }
        this->_inventorySlots = existing.getInventorySlots();
    }
    return (*this);
}

//-------------Get Public Functions------------------

std::string const & Character::getName(void)const
{
    return (this->_name);
}

int Character::getInventorySlots(void)const
{
    return (this->_inventorySlots);
}

AMateria* Character::getInventoryItem(int location)const
{
    if (location > -1 && location < 4)
        return(this->_inventory[location]);
    else 
        std::cout << "Index out of range. AMAteria is NULL" << std::endl;
    return (NULL);
}

//-------------Other Public Functions------------------

void Character::equip(AMateria* m)
{

    if (m && this->_inventorySlots < 4)
    {
        this->_inventory[this->_inventorySlots] = m;
        _inventorySlots++;
    }
    else
        std::cout << "Inventory full. No more free slots." << std::endl;
}

void Character::unequip(int indx)
{
    if (indx > -1 && indx < 4)
    {
        this->_inventory[indx] = NULL;
        if (this->_inventorySlots == indx - 1)
            this->_inventorySlots--;
    }
    else
        std::cout << "Index out of range. Unable to unequip inventory item" << std::endl;
}

void Character::use(int indx, ICharacter& target)
{
    this->getInventoryItem(indx)->use(target);
}