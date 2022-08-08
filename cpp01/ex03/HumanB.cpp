#include "HumanB.hpp"
#include <iostream>

HumanB:: HumanB(std::string name)
{
	_nameB = name;
	_weaponB = NULL;
	return;
}

HumanB:: ~HumanB(void)
{
	return;
}

void HumanB::setWeapon(Weapon& weaponType)
{
	_weaponB = &weaponType;
}

void HumanB::attack(void)
{
	if (_weaponB != NULL)
	{
		std::cout << _nameB;
		std::cout << " attacks with their weapon ";
		std::cout << _weaponB->getType() << std::endl;
	}
	else
		std::cout << "No weapon!" << std::endl;
}