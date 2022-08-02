#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:

	std::string _name;
	Weapon weaponA;

public:
	HumanA(std::string name, Weapon weaponName);
	~HumanA(void);

	void setWeapon(std::string type);

};

#endif