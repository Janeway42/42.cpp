#include "ScavTrap.hpp"

//----------Constructors & Destructors----------------

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
	setHit(100);
	setEnergy(50);
	setDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &existing)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = existing;
}

// ScavTrap& ScavTrap::operator = (ScavTrap const &existing)
// {

// 	existing.getName();

// 	if (this != &existing)
// 	{
// 		setName(existing.getName());
// 		setHit(100);
// 		setEnergy(50);
// 		setDamage(20);
// 	}
// 	return (*this);
// }

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor " << this->getName() << " has been called" << std::endl;
}

//---------------Functions----------------

void ScavTrap::guardGate()
{

	std::cout << "Scavtrap " << this->getName() << " is now in Gate Keeper mode" << std ::endl;

}