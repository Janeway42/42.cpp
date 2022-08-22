#include "FragTrap.hpp"

//----------Constructors & Destructors----------------

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
	setHit(100);
	setEnergy(100);
	setDamage(30);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->getName() << " destructor called" << std::endl;
}

//----------Functions------------------------

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " sends positive high fives!" << std::endl;
}