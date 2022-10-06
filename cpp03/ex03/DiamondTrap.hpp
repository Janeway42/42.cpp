#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap 
{
private:
	std::string _name;

public:
	DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &existing);

	~DiamondTrap(void);

    DiamondTrap& operator =(DiamondTrap const &existing);

	void whoAmI();
    void attack(const std::string& target);


	void setDiamondName(std::string name);
    
    std::string getDiamondName(void)const;
    int getDiamondHit(void)const;
    int getDiamondEnergy(void)const;
    int getDiamondDamage(void)const;

};

#endif