#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &existing);
	~ScavTrap(void);

	ScavTrap& operator = (ScavTrap const &existing);

	void guardGate();
    void attack(const std::string& target);


    std::string getScavName(void);
    int getScavHit(void)const;
    int getScavEnergy(void)const;
    int getScavDamage(void)const;

};

#endif