#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

void checkleaks(void){
    system("leaks -q amateria");
}

int main(void)
{
    AMateria* Ice1 = new Ice();
    AMateria* Cure1 = new Cure();
    std::cout << std::endl;

    std::cout << "type Ice1: " << Ice1->getType() << std::endl;
    std::cout << "type Cure1: " << Cure1->getType() << std::endl;
    std::cout << std::endl;

    AMateria* Ice2 = (*Ice1).clone();  // Ice1->clone()

    std::cout << "type Ice2: " << Ice2->getType() << std::endl;
    std::cout << std::endl;

    Character* Man1 = new Character();
    Man1->equip(Ice1);
    std::cout << "Man 1 equip 1: " << (*Man1).getInventoryItem(0) << std::endl;
    std::cout << std::endl;

    delete(Ice1);
    delete(Cure1);
    delete(Ice2);
    delete(Man1);

    std::cout << std::endl;
    atexit(checkleaks);
   // system("leaks -q amateria");
}