#include "DiamondTrap.hpp"

//----------Constructors & Destructors----------------

DiamondTrap::DiamondTrap(void): FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap("_clap_" + name), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap " <<  this->getScavName() << " constructor called\n" <<std::endl;

	FragTrap tempFrag("temp");

    setDiamondName(name);
	FragTrap::setHit(tempFrag.getFragHit());
	FragTrap::setDamage(tempFrag.getFragDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &existing)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = existing;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " <<  this->_name << " destructor called" <<std::endl;
}

//------------------Operators--------------------------

DiamondTrap& DiamondTrap::operator =(DiamondTrap const &existing)
{
    std::cout << "DiamondTrap " << this->_name << " copy assignment oerator called" << std::endl;
    if (this != &existing)
    {
        _name = existing.getDiamondName();
        ScavTrap::setName(_name);
        FragTrap::setHit(existing.getDiamondHit());
	    ScavTrap::setEnergy(existing.getDiamondEnergy());
	    FragTrap::setDamage(existing.getDiamondDamage());
    }
    return (*this);
}

//----------------Public Get Functions----------------

void DiamondTrap::setDiamondName(std::string name)
{
    this->_name = ScavTrap::getName(); 
}

std::string DiamondTrap::getDiamondName(void)const
{
    return (this->_name);
}

int DiamondTrap::getDiamondHit(void)const
{
    return (FragTrap::getFragHit());
}

int DiamondTrap::getDiamondEnergy(void)const
{
    return (ScavTrap::getScavEnergy());
}

int DiamondTrap::getDiamondDamage(void)const
{
    return (FragTrap::getFragDamage());
}

//----------------Other Public Functions----------------

void DiamondTrap::whoAmI(void)
{
	std::cout << "Diamond name: " << this->_name << std::endl;
	std::cout << "Clap name:    " << ScavTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
