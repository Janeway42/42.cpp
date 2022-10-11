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
    AMateria* Cure2 = new Cure();
    AMateria* Cure3 = new Cure();
    std::cout << std::endl;

    std::cout << "-------------- read type tests --------------------\n\n";

    std::cout << "type Ice1: " << Ice1->getType() << std::endl;
    std::cout << "type Cure1: " << Cure1->getType() << std::endl;
    std::cout << "type Cure2: " << Cure2->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "-------------- clone tests --------------------\n\n";

    AMateria* Ice2 = (*Ice1).clone();  // Ice1->clone()
    std::cout << "type Ice2: " << Ice2->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "-------------- read inventory tests --------------------\n\n";

    Character* Man1 = new Character("The Man");
    Man1->equip(Ice1);
    std::cout << "Man 1 inventory 0: " << Man1->getInventoryItem(0)->getType() << std::endl;
    Man1->equip(Cure1);
    std::cout << "Man 1 inventory 1: " << (*(*Man1).getInventoryItem(1)).getType() << std::endl;
    Man1->equip(Ice2); 
    std::cout << "Man 1 inventory 2: " << (*(*Man1).getInventoryItem(2)).getType() << std::endl;
    Man1->equip(Cure2);
    std::cout << "Man 1 inventory 3: " << (*(*Man1).getInventoryItem(3)).getType() << std::endl;


    Man1->equip(Cure3);
    if ((*Man1).getInventoryItem(4) != NULL)
        std::cout << "Man 1 inventory 4: " << (*(*Man1).getInventoryItem(4)).getType() << std::endl;
    else 
        std::cout << "Man 1 inventory 4 is NULL\n";
    std::cout << std::endl;

    std::cout << "-------------- use tests --------------------\n\n";
    Ice1->use(*Man1);
    Cure1->use(*Man1);
    (*(*Man1).getInventoryItem(3)).use(*Man1);
    Man1->use(0, *Man1);

    std::cout << std::endl;

    std::cout << "-------------- unequip tests --------------------\n\n";

    Man1->unequip(2);
    if ((*Man1).getInventoryItem(2) != NULL)
        std::cout << "Man 1 equip 2: " << (*(*Man1).getInventoryItem(2)).getType() << std::endl;
    else 
    std::cout << "Man 1 inventory 2 is NULL\n";
    std::cout << std::endl;

    std::cout << "-------------- destructors --------------------\n\n";

    delete(Ice1);
    delete(Cure1);
    delete(Ice2);
    delete(Man1);
    delete(Cure2);
    delete(Cure3);
    std::cout << std::endl;

    std::cout << "-------------- leaks check --------------------\n\n";

    atexit(checkleaks);
   // system("leaks -q amateria");
}