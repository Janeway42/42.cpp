#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _nameB;
	Weapon* _weaponB;

public:

	HumanB(std::string name);
	~HumanB(void);

	void setWeapon(Weapon& weaponType);
	void attack(void);
};

#endif