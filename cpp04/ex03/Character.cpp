#include "Character.hpp"

//-----------Constructors & Destructors----------

Character::Character(void)
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    this->_inventorySlots = 0;
}

Character::Character(std::string name)
{
    std::cout << "Character " << this->_name << " constructor called" << std::endl;
    this->_name = name;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    this->_inventorySlots = 0;
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
    this->_inventorySlots = existing._inventorySlots;
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
    if (location < 0 || location > 3)
        std::cout << "Character inventory index request is out of range" << std::endl;
    else
    {
        if (this->_inventorySlots == 0)
            std::cout << "Inventory is empty. AMateria is NULL." << std::endl;
        else
            return(this->_inventory[location]); 
    }
    return (NULL);
}

//-------------Other Public Functions------------------

void Character::equip(AMateria* m)
{
    if (m)
    {
        if (this->_inventorySlots < 4)
        {
            this->_inventory[this->_inventorySlots] = m;
            _inventorySlots++;
        }
        else
            std::cout << "Character is full. No more free slots." << std::endl; 
    }
    else
        std::cout << "Unavailable AMateria input" << std::endl;
}

void Character::unequip(int indx)
{
    if (this->_inventorySlots == 0)
        std::cout << "Character inventory is empty. Go do some shopping!" << std::endl;
    else if (indx > -1 && indx < 4)
    {
        if (this->_inventory[indx] == NULL)
            std::cout << "Character inventory slot already empty" << std::endl;
        else
        {
            this->_inventory[indx] = NULL;
            this->_inventorySlots--;   // Check !!!
        }
    }
    else
        std::cout << "Index out of range. Unable to unequip inventory item" << std::endl;
}

void Character::use(int indx, ICharacter& target)
{
    if (indx < 0 || indx > 3)
        std::cout << "Input index out of range" << std::endl;
    else if (this->_inventorySlots == 0)
        std::cout << "This character has no inventory to use" << std::endl;
    else
        this->getInventoryItem(indx)->use(target);
}