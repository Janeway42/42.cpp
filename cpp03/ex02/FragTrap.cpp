#include "FragTrap.hpp"

//----------Constructors & Destructors----------------

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
	setHit(100);
	setEnergy(100);
	setDamage(30);
}

FragTrap::FragTrap(const FragTrap &existing)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = existing;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->getName() << " destructor called" << std::endl;
}

//------------------Operators--------------------------

FragTrap& FragTrap::operator =(FragTrap const &existing)
{
    std::cout << "FragTrap " << this->getName() << " copy asignment operator called" << std::endl;
    if (this != &existing)
    {
        setName(existing.getName());
        setHit(existing.getHit());
        setEnergy(existing.getEnergy());
        setDamage(existing.getDamage());
    }
    return (*this);
}

//----------Public Functions------------------------

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " sends positive high fives!" << std::endl;
}