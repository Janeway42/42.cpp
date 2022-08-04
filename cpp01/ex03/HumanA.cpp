#include "HumanA.hpp"
#include <iostream>

HumanA:: HumanA(std::string name, Weapon& weaponType) : _weaponA(weaponType)
{
	_nameA = name;
	// _weaponA = weaponType;
	return;
}

HumanA:: ~HumanA(void)
{
	return;
}

void HumanA::attack(void)
{
	std::cout << _nameA;
	std::cout << " attacks with their weapon ";
	std::cout << _weaponA.getType() << std::endl;
}