#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "------------- ClapTrap --------------\n\n";
	
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

	std::cout << "------------- ScavTrap --------------\n\n";

    ScavTrap Three;
	ScavTrap Four("The tower");
	std::cout << std::endl;

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

	std::cout << "------------- FragTrap --------------\n\n";

    FragTrap Five;
	FragTrap Six("The Ring");
	std::cout << std::endl;

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