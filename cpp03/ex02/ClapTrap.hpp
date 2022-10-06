#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;

protected:
	void setName(std::string name);
	void setHit(unsigned int val);
	void setEnergy(unsigned int val);
	void setDamage(unsigned int val);

	std::string getName()const;
    int getHit(void)const;
    int getEnergy(void)const;
    int getDamage(void)const;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &existing);
	~ClapTrap(void);

	ClapTrap& operator = (ClapTrap const &existing);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif