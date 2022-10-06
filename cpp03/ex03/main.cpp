#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    DiamondTrap Nine("Diamondish");
    std::cout << std::endl;

    Nine.whoAmI();
    std::cout << std::endl;

    std::cout << "Diamond Hit:     " << Nine.getDiamondHit() << std::endl;
    std::cout << "FragTrap Hit:    " << Nine.getFragHit() << std::endl;
    std::cout << "Diamond Energy:  " << Nine.getDiamondEnergy() << std::endl;
    std::cout << "ScavTrap Energy: " << Nine.getScavEnergy() << std::endl;
    std::cout << "Diamond Damage:  " << Nine.getDiamondDamage() << std::endl;
    std::cout << "FragTrap Damage: " << Nine.getFragDamage() << std::endl;
    std::cout << std::endl;

	Nine.highFivesGuys();
	Nine.attack("Frodo");
	Nine.takeDamage(58);
	Nine.beRepaired(6);
	Nine.takeDamage(158);
    std::cout << std::endl;

	return (0);
}