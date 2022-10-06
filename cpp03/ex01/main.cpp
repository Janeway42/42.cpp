#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ScavTrap One;
	ScavTrap Two("Frodo");
	std::cout << std::endl;

    std::cout << "------------ Basic Tests -----------\n\n";

    std::cout << "One: " << One.getScavName() << std::endl;
    std::cout << "Hit One: " << One.getScavHit() << std::endl;
    std::cout << "Two: " << Two.getScavName() << std::endl;
    std::cout << "Hit Two: " << Two.getScavHit() << std::endl;
	std::cout << std::endl;

	One.guardGate();
	One.attack("Frodo");
	One.takeDamage(20);
	One.beRepaired(6);
	std::cout << std::endl;

    Two.guardGate();
	Two.attack("The Ring");
	Two.takeDamage(9);

	Two.beRepaired(10);
	Two.takeDamage(12);
	Two.beRepaired(3);
	
    Two.takeDamage(150);
	std::cout << std::endl;

    std::cout << "One: " << One.getScavName() << std::endl;
    std::cout << "Hit One: " << One.getScavHit() << std::endl;
    std::cout << "Two: " << Two.getScavName() << std::endl;
    std::cout << "Hit Two: " << Two.getScavHit() << std::endl;
	std::cout << std::endl;

    std::cout << "------------ Copy Test -----------\n\n";

    std::cout << "One: " << One.getScavName() << std::endl;
    std::cout << "Hit One: " << One.getScavHit() << std::endl;
    std::cout << "Energy One: " << One.getScavEnergy() << std::endl;
    std::cout << "Damage One: " << One.getScavDamage() << std::endl;

    std::cout << "Two: " << Two.getScavName() << std::endl;
    std::cout << "Hit Two: " << Two.getScavHit() << std::endl;
    std::cout << "Energy Two: " << Two.getScavEnergy() << std::endl;
    std::cout << "Damage Two: " << Two.getScavDamage() << std::endl;

    One = Two;
	std::cout << std::endl;
    std::cout << "One: " << One.getScavName() << std::endl;
    std::cout << "Hit One: " << One.getScavHit() << std::endl;
    std::cout << "Energy One: " << One.getScavEnergy() << std::endl;
    std::cout << "Damage One: " << One.getScavDamage() << std::endl;

    std::cout << "Two: " << Two.getScavName() << std::endl;
    std::cout << "Hit Two: " << Two.getScavHit() << std::endl;
    std::cout << "Energy Two: " << Two.getScavEnergy() << std::endl;
    std::cout << "Damage Two: " << Two.getScavDamage() << std::endl;

    std::cout <<"------------ Dead Scav Tests -----------\n\n";

	Two.guardGate();
	Two.attack("The Ring");
	Two.takeDamage(9);
	Two.beRepaired(10);
	Two.takeDamage(150);
	std::cout << std::endl;

    std::cout << "Two: " << Two.getScavName() << std::endl;
    std::cout << "Hit Two: " << Two.getScavHit() << std::endl;
    std::cout << "Energy Two: " << Two.getScavEnergy() << std::endl;
    std::cout << "Damage Two: " << Two.getScavDamage() << std::endl;
	std::cout << std::endl;

    std::cout <<"------------ End Tests -----------\n\n";
    
	return (0);
}