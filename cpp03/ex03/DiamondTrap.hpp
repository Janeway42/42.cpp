#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap 
{
private:
	std::string _name;

protected:
	DiamondTrap(void);
	// void setDiamondName(std::string name);

public:
	DiamondTrap(std::string name);
	~DiamondTrap(void);

	void whoAmI();
};

#endif