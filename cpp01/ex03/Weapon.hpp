#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
private:
	std::string _type;

public:

	Weapon(std::string type);
	~Weapon(void);

	const	std::string& getType();
	void	setType(std::string type);
};

#endif


// A setType() member function that sets type using the new one passed as parameter.