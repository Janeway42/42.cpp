#include "HumanA.hpp"

HumanA:: HumanA(std::string name, Weapon weaponName)
{
	_name = name;
	setWeapon(weaponName);
	return;
}

HumanA:: ~HumanA(void)
{
	return;
}

void setWeapon(Weapon weaponName)
{
	weaponA = weaponName;
}