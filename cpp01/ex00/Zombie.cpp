#include <string>
#include "Zombie.hpp"

Zombie::	Zombie(std::string input)
{
	_name = input;

	std::cout << _name, std::cout << " is now alive" << std::endl;
	return;
}

Zombie::	~Zombie(void)
{
	std::cout << _name, std::cout << " has been destroyed" << std::endl;
	return;
}

void Zombie::announce(void)
{
	std::cout << _name, std::cout << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}