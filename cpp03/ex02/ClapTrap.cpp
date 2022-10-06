#include "ClapTrap.hpp"

//----------Constructors & Destructors----------------

ClapTrap::ClapTrap(void): _name("annonymous")
{
	std::cout << "ClapTrap default constructor has been called" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name): _name(name)
{
	std::cout << "ClapTrap "<< name << " constructor has been called" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &existing)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = existing;
}

//------------------Operators--------------------------

ClapTrap& ClapTrap::operator = (ClapTrap const &existing)
{
	std::cout << "ClapTrap copy assignment operator has been called" << std::endl;
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
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

//----------Protected Set Functions--------------

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

//----------Protected Get Functions--------------

std::string ClapTrap::getName(void)const
{
	return (this->_name);
}

int ClapTrap::getHit(void)const 
{
    return (this->_hitPoints);
}

int ClapTrap::getEnergy(void)const
{
    return (this->_energyPoints);
}

int ClapTrap::getDamage(void)const
{
    return (this->_attackDamage);
}

//----------Public Functions------------------------

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " does not have enough energy points to attack" << std:: endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " has already bit the bullet." << std::endl;
	else if (this->_hitPoints <= amount)
	{
		std::cout << "ClapTrap " << this->_name << " bit the bullet." << std::endl;
		this->_hitPoints = 0;
	}
	else if (this->_hitPoints > amount)
	{
		std::cout << "ClapTrap " << this->_name << " is being attacked, incuring " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " is being reppaied with " << amount << " points" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
    else if (this->_energyPoints == 0 && this->_hitPoints > 0)
		std::cout << "ClapTrap " << this->_name << " doesn't have enought energy points to be repaired." << std::endl;

    else
		std::cout << "ClapTrap " << this->_name << " has already bit the bullet." << std::endl;
}