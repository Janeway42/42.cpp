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
    std::cout << "Energy One: " << One.getScavEnergy() << std::endl;
    std::cout << "Attack One: " << One.getScavDamage() << std::endl;
    std::cout << "Two: " << Two.getScavName() << std::endl;
    std::cout << "Hit Two: " << Two.getScavHit() << std::endl;
    std::cout << "Energy Two: " << Two.getScavEnergy() << std::endl;
    std::cout << "Attack Two: " << Two.getScavDamage() << std::endl;
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
	std::cout << std::endl;

    std::cout << "One: " << One.getScavName() << std::endl;
    std::cout << "Hit One: " << One.getScavHit() << std::endl;
    std::cout << "Energy One: " << One.getScavEnergy() << std::endl;
    std::cout << "Attack One: " << One.getScavDamage() << std::endl;
    std::cout << "Two: " << Two.getScavName() << std::endl;
    std::cout << "Hit Two: " << Two.getScavHit() << std::endl;
    std::cout << "Energy Two: " << Two.getScavEnergy() << std::endl;
    std::cout << "Attack Two: " << Two.getScavDamage() << std::endl;
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
	std::cout << std::endl;

    std::cout <<"------------ No Energy Tests -----------\n\n";
     
    for (int i = Two.getScavEnergy(); i > 0; i--)
    {
        std::cout << i << std::endl;
        Two.beRepaired(1);
    }
    Two.attack("The Ring");
	Two.beRepaired(10);
	Two.guardGate();

    std::cout << "Two: " << Two.getScavName() << std::endl;
    std::cout << "Hit Two: " << Two.getScavHit() << std::endl;
    std::cout << "Energy Two: " << Two.getScavEnergy() << std::endl;
    std::cout << "Damage Two: " << Two.getScavDamage() << std::endl;
	std::cout << std::endl;

    std::cout <<"------------ Dead Scav Tests -----------\n\n";

    ScavTrap Three("Another Frodo");
	std::cout << std::endl;

	Three.takeDamage(150);
	Three.guardGate();
	Three.attack("The Ring");
	Three.beRepaired(10);
	Three.takeDamage(9);
	std::cout << std::endl;

    std::cout << "Two: " << Three.getScavName() << std::endl;
    std::cout << "Hit Two: " << Three.getScavHit() << std::endl;
    std::cout << "Energy Two: " << Three.getScavEnergy() << std::endl;
    std::cout << "Damage Two: " << Three.getScavDamage() << std::endl;
	std::cout << std::endl;

    std::cout <<"------------ End Tests -----------\n\n";
    
	return (0);
}