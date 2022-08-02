#include <string>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << _name, std::cout << "Zombie alive" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << _name, std::cout << " has been destroyed" << std::endl;
	return;
}

void Zombie::announce(void)
{
	std::cout << _name, std::cout << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}

void Zombie::nameZombie(std::string name)
{
	_name = name;
}