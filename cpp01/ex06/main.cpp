#include "Harl.hpp"
#include <iostream>

int	inputCheck(int argc, std::string input, std::string array[])
{
	int out = 1;

	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}

	for (int i = 0; i < 4; i++)
		if (input.compare(array[i]) == 0)
			out = 0;

	if (out == 1)
		std::cout << "Invalid level" << std::endl;

	return (out);
}

int main (int argc, char **argv)
{
	Harl warnings;
	std::string levels[4] = {"DEBUGG", "INFO", "WARNING", "ERROR"};

	if (inputCheck(argc, argv[1], levels) == 1)
		return (1);

	warnings.complain(argv[1]);

	return (0);
}