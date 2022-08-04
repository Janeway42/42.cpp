#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:

	std::string _nameA;
	Weapon& _weaponA;

public:
	HumanA(std::string name, Weapon& weaponName);
	~HumanA(void);

	// void setWeapon(Weapon weaponName);
	void attack(void);

};

#endif