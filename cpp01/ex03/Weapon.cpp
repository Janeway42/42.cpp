#include "Weapon.hpp"
#include <iostream>

Weapon:: Weapon(void)
{
	return;
}

Weapon:: Weapon(std::string weaponType)
{
	_type = weaponType;
}

Weapon:: ~Weapon(void)
{
	return;
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

const	std::string& Weapon::getType()
{	
	// std::string& typeREF = _type;
	// return (typeREF);
	return (_type);
}
