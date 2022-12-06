#include <iostream>
#include <string>
#include "CheckInput.hpp"
#include "ProcessItem.hpp"

int basicChecks(std::string str)
{
	if (str.length() == 0)
	{
		std::cout << "Empty string. Try again!" << std::endl;
		return (1);
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isprint((int)str[i]) == 0)
		{
			std::cout << "Not printable. Try again!" << std::endl;
			return (1);
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" <<std::endl;
		return (1);
	}
	if (basicChecks(argv[1]) == 1)
		return (1);
	if (processInput(argv[1]) == 1)
		return (1);	
	return (0);
}