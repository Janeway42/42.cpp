#include "ScavTrap.hpp"

//----------Constructors & Destructors----------------

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
    setHit(100);
	setEnergy(50);
	setDamage(20);
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
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

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->getName() << " destructor called" << std::endl;
}

//------------------Operators--------------------------

ScavTrap& ScavTrap::operator = (ScavTrap const &existing)
{
    std::cout << "Scavtrap " << this->getName() << " copy assignment operator called" << std::endl;
	if (this != &existing)
	{
		setName(existing.getName());
        setHit(existing.getHit());
        setEnergy(existing.getEnergy());
		setDamage(existing.getDamage());
	}
	return (*this);
}

//---------------Public Get Functions----------------

std::string ScavTrap::getScavName(void)
{
    return (this->getName());
}

int ScavTrap::getScavHit(void)
{
    return (this->getHit());
}

int ScavTrap::getScavEnergy(void)
{
    return (this->getEnergy());
}

int ScavTrap::getScavDamage(void)
{
    return(this->getDamage());
}

//---------------Aditional Public Functions----------------

void ScavTrap::guardGate()
{
    if (this->getHit() > 0)
    	std::cout << "Scavtrap " << this->getName() << " is now in Gate Keeper mode" << std ::endl;
    else
        std::cout << "ScavTrap " << this->getName() << " can't protect the gate because it has already bit the bullet" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getHit() == 0)
        std::cout << "ScavTrap " << this->getName() << " can't attack " << target << " as it has already bit the bullet" << std::endl;
	else if (this->getEnergy() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << std::endl;
		this->setEnergy(this->getEnergy() - 1);
	}
	else
		std::cout << "ScavTrap " << this->getName() << " does not have enough energy points to attack" << std:: endl;
}
