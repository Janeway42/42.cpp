#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ScavTrap One;
	ScavTrap Two("Frodo");

	std::cout << std::endl;
	One.guardGate();
	One.attack("Frodo");
	One.takeDamage(8);
	One.beRepaired(6);
	std::cout << std::endl;

	Two.guardGate();
	Two.attack("The Ring");
	Two.takeDamage(9);
	Two.beRepaired(10);
	Two.takeDamage(15);
	std::cout << std::endl;

	return (0);
}