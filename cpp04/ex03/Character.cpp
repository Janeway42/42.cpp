#include "Character.hpp"

//-----------Constructors & Destructors----------

Character::Character(void)
{
    std::cout << "Character default constructor called" << std::endl;
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
    // Character* temp = new Character();  // deep copy 

    *this = existing;
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
}

//----------------- Operators--------------------

Character& Character::operator = (Character const &existing)
{
    std::cout << "Character copy assignemnt operator called" << std::endl;  // deep copy
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



void Character::equip(AMateria* m)
{

    if (this->_inventorySlots < 4)  // unexisting Materia????
    {
        this->_inventory[this->_inventorySlots] = m;
        _inventorySlots++;
    }
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

AMateria* Character::getInventoryItem(int location)const
{
    if (location > -1 && location < 4)
        return(this->_inventory[location]);
    else 
        std::cout << "Index out of range. AMAteria is NULL" << std::endl;
    return (NULL);
}

void Character::use(int indx, ICharacter& target)
{
    this->getInventoryItem(indx)->use(target);
}

std::string const & Character::getName(void)const
{
    return (this->_name);
}

