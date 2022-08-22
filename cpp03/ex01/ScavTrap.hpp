#ifndef SCAVTRAP_HPP
#define SCAVTRAP_CPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &existing);
	~ScavTrap(void);

	// ScavTrap& operator = (ScavTrap const &existing);

	void guardGate();
};

#endif