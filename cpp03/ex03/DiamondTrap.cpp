#include "DiamondTrap.hpp"
#include <iostream>

//----------Constructors & Destructors----------------

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	FragTrap tempFrag;
	ScavTrap tempScav;

	_name = name;
	std::cout << "DiamondTrap " <<  this->_name << " constructor called" <<std::endl;

	ClapTrap::setName();
	FragTrap::setHit(tempFrag.getHitPoints());
	ScavTrap::setEnergy(tempScav.getEnergyPoints());
	FragTrap::setDamage(tempFrag.getAttackDamage());
}

DiamondTrap::~DiamondTrap(void)
{

	std::cout << "DiamondTrap " <<  this->_name << " destructor called" <<std::endl;
}

//-------------Protected Functions----------------

// void DiamondTrap::setDiamondName(std::string name)
// {

// }

//----------------Public Functions----------------

void DiamondTrap::whoAmI(void)
{
	std::cout << "Diamond name: " << this->_name << std::endl;
	std::cout << "Clap name: " << ClapTrap::getName() << std::endl;
}