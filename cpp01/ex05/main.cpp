#include "Harl.hpp"
#include <iostream>

int main (void)
{
	Harl warnings;

	warnings.complain("DEBUG");
	std::cout << std::endl;
	warnings.complain("INFO");
	std::cout << std::endl;
	warnings.complain("WARNING");
	std::cout << std::endl;
	warnings.complain("ERROR");
	std::cout << std::endl;

	return (0);
}