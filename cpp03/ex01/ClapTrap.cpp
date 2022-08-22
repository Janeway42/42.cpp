#include "ClapTrap.hpp"

//----------Constructors & Destructors----------------

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor has been called" << std::endl;
	_name = "no name";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap "<< name << " constructor has been called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &existing)
{
	std::cout << "Copy constructor has been called" << std::endl;
	*this = existing;
}

ClapTrap& ClapTrap::operator = (ClapTrap const &existing)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	if (this != &existing)
	{
		_name = existing._name;
		_hitPoints = existing._hitPoints;
		_energyPoints = existing._energyPoints;
		_attackDamage = existing._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor " << this->_name << " has been called" << std::endl;
}

//----------Protected Functions--------------

void ClapTrap::setName(std::string name)
{
	_name = name;
}

void ClapTrap::setHit(unsigned int val)
{
	_hitPoints = val;
}

void ClapTrap::setEnergy(unsigned int val)
{
	_energyPoints = val;
}

void ClapTrap::setDamage(unsigned int val)
{
	_attackDamage = val;
}

std::string ClapTrap::getName(void)

{
	return (this->_name);
}

//----------Functions------------------------

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "Not enough energy points" << std:: endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " has already bit the bullet." << std::endl;
	if (this->_hitPoints <= amount)
	{
		std::cout << "ClapTrap " << this->_name << " bit the bullet." << std::endl;
		this->_hitPoints = 0;
	}
	if (this->_hitPoints > amount)
	{
		std::cout << "ClapTrap " << this->_name << " is being attacked, incuring " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " has already bit the bullet." << std::endl;
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " is being reppaied with " << amount << " points" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
}