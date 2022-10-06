#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap One;
	ClapTrap Two("Frodo");
	std::cout << std::endl;

	ScavTrap Three;
	ScavTrap Four("The tower");
	std::cout << std::endl;

	FragTrap Five;
	FragTrap Six("The Ring");
	std::cout << std::endl;

	std::cout << "---------- ClapTrap ----------" << std::endl;
	One.attack("Frodo");
	One.takeDamage(8);
	One.beRepaired(6);
	std::cout << std::endl;

	Two.attack("The Ring");
	Two.takeDamage(9);
	Two.beRepaired(10);
	Two.takeDamage(15);
	std::cout << std::endl;

	std::cout << "---------- ScavTrap ----------" << std::endl;
	Three.guardGate();
	Three.attack("Frodo");
	Three.takeDamage(8);
	Three.beRepaired(6);
	std::cout << std::endl;

	Four.guardGate();
	Four.attack("The Ring");
	Four.takeDamage(9);
	Four.beRepaired(10);
	Four.takeDamage(15);
	std::cout << std::endl;

	std::cout << "---------- FragTrap ----------" << std::endl;
	Five.highFivesGuys();
	Five.attack("Frodo");
	Five.takeDamage(8);
	Five.beRepaired(6);
	std::cout << std::endl;

	Six.highFivesGuys();
	Six.attack("The Ring");
	Six.takeDamage(9);
	Six.beRepaired(10);
	Six.takeDamage(15);
	std::cout << std::endl;

	return (0);
}