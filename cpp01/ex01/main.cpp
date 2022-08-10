#include <iostream>
#include <string>
#include "Zombie.hpp"

int main (void)
{
	Zombie	*creature;
	int		i;
	int		nr;
	std::string buffer;
	std::string temp;

	std::cout << "Input number of zombies:" << std::endl;	
	while (true)
	{
		std::getline(std::cin, buffer);
		try
		{
			nr = stoi(buffer);
			temp = std::to_string(nr);
			if (temp.compare(buffer) != 0)
				std::cout << "Please input a number!" << std::endl;
			else
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