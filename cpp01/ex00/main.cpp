#include "Zombie.hpp"

int main(void)
{
	Zombie *brainEater;

	brainEater = new Zombie("Heap Zombie");
	brainEater->announce();
	delete(brainEater);

	randomChump("Stack Zombie");

	return(0);
}