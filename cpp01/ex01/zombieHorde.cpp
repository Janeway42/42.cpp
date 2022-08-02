#include <string>
#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*hoarde;
	int		i;
	
	hoarde = new Zombie[N];
	for (i = 0; i < N; i++)
		hoarde[i].nameZombie(name);

	return (hoarde);
}