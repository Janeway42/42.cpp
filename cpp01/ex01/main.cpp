#include <iostream>
#include <string>
#include "Zombie.hpp"

int main (void)
{
	Zombie	*creature;
	int		i;
	int		nr;
	std::string temp;

	std::cout << "Input number of zombies:" << std::endl;
	std::getline(std::cin, temp);

	while (true)
	{
		try
		{
			nr = stoi(temp);
			break;
		}
		catch(const std::exception& e)
		{
			std::cout << "Please input a number!" << std::endl;
		}
	}

	creature = zombieHorde(nr, "Brain_Eater");

	for (i = 0; i < nr; i++)
		creature[i].announce();

	delete [] creature;

	return (0);
}