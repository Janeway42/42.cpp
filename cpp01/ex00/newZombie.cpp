#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *new_creature = new Zombie(name);
	return (new_creature);
}
