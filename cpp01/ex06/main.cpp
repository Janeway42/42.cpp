#include "Harl.hpp"
#include <iostream>

int main (int argc, char **argv)
{
	Harl warnings;
	int	levelNumber;
	
	if (argc == 2)
	{
		warnings.complain(argv[1]);
		return (0);
	}
	std::cout << "Wrong number of arguments" << std::endl;
	return (1);
}