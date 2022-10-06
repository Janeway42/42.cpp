#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
    FragTrap(const FragTrap &existing);
	~FragTrap(void);

    FragTrap& operator = (FragTrap const &existing);

	void highFivesGuys(void);

    std::string getFragName();
    int getFragHit(void)const;
    int getFragEnergy(void)const;
    int getFragDamage(void)const;

};

#endif