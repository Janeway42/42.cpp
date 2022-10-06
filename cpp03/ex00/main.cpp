#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap One;
	ClapTrap Two("Frodo");
	std::cout << std::endl;

    One.attack("Frodo");
	One.takeDamage(8);
	One.beRepaired(6);
	std::cout << std::endl;

	Two.attack("The Ring");
	Two.takeDamage(9);
	Two.beRepaired(10);
	Two.takeDamage(15);
	std::cout << std::endl;

	return (0);
}