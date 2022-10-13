#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void checkleaks(void){
    system("leaks -q amateria");
}

int main(void)
{
    std::cout << "-------------- subject tests --------------------\n\n";

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // ICharacter* bob = new Character("bob");

    // me->use(0, *bob);
    // me->use(1, *bob);

    // delete(bob);
    delete(me);
    delete(src);

    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "-------------- other tests --------------------\n\n";



    AMateria* Ice1 = new Ice();
    AMateria* Cure1 = new Cure();
    AMateria* Cure2 = new Cure();
    std::cout << std::endl;

    std::cout << "-------------- read type tests --------------------\n\n";

    std::cout << "type Ice1:  " << Ice1->getType() << std::endl;
    std::cout << "type Cure1: " << Cure1->getType() << std::endl;
    std::cout << "type Cure2: " << Cure2->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "-------------- clone tests --------------------\n\n";

    AMateria* Ice2 = (*Ice1).clone();
    std::cout << "type Ice2: " << Ice2->getType() << std::endl;
    std::cout << std::endl;
    AMateria* Cure3 = Cure2->clone();
    std::cout << "type Cure 3: " << Cure3->getType() << std::endl;
    std::cout << std::endl;


     printf("ice 2: %p\n", Ice2);

    std::cout << "-------------- read inventory tests --------------------\n\n";

    ICharacter* Man1 = new Character("The Man");
    std::cout << std::endl;

    Man1->equip(Ice1);
    std::cout << "Man 1 inventory 0: " << Man1->getInventoryItem(0)->getType() << std::endl;
    Man1->equip(Cure1);
    std::cout << "Man 1 inventory 1: " << (*(*Man1).getInventoryItem(1)).getType() << std::endl;
    Man1->equip(Ice2); 
    std::cout << "Man 1 inventory 2: " << (*(*Man1).getInventoryItem(2)).getType() << std::endl;
    Man1->equip(Cure2);
    std::cout << "Man 1 inventory 3: " << (*(*Man1).getInventoryItem(3)).getType() << std::endl;
    std::cout << std::endl;

    Man1->equip(Cure3);
    if ((*Man1).getInventoryItem(4) != NULL)
        std::cout << "Man 1 inventory 4: " << (*(*Man1).getInventoryItem(4)).getType() << std::endl;
    else 
        std::cout << "Man 1 inventory 4 is NULL\n";
    std::cout << std::endl;

    std::cout << "-------------- use tests --------------------\n\n";
    std::cout << "Ice1 use: \n";
    Ice1->use(*Man1);
    std::cout << "Cure1 use: \n";
    Cure1->use(*Man1);
    std::cout << "(Man1 inventory[3]) use: \n";
    (*(*Man1).getInventoryItem(3)).use(*Man1);
    std::cout << "Man1 direct use (inventory[0]): \n";
    Man1->use(0, *Man1);
    std::cout << std::endl;

    std::cout << "-------------- unequip tests --------------------\n\n";
   
    AMateria* temp;
    temp = Man1->getInventoryItem(2);
    printf("temp: %p\n", temp);
    printf("ice: %p\n", Man1->getInventoryItem(2));
   
    Man1->unequip(2);
    if ((*Man1).getInventoryItem(2) != NULL)
        std::cout << "Man 1 equip 2: " << (*(*Man1).getInventoryItem(2)).getType() << std::endl;
    else
    {
        std::cout << "Man 1 inventory 2 is NULL\n";
        delete(temp);
    }        
    std::cout << std::endl;

    std::cout << "-------------- destructors --------------------\n\n";

    delete(Cure3);
    delete(Man1);
    std::cout << std::endl;

    std::cout << "-------------- MateriaSource Tests --------------------\n\n";

    IMateriaSource* materia2 = new MateriaSource();
    std::cout << std::endl;

    materia2->learnMateria(new Ice());
    std::cout << "index learned: " << materia2->getIndex() << std::endl;
    std::cout << "Materia learned 0: " << materia2->getLearnedMateria(0)->getType() << std::endl;

    materia2->learnMateria(new Cure());
    std::cout << "Materia learned 1: " << materia2->getLearnedMateria(1)->getType() << std::endl;

    materia2->learnMateria(new Ice());
    std::cout << "Materia learned 2: " << materia2->getLearnedMateria(2)->getType() << std::endl;

    materia2->learnMateria(new Ice());
    std::cout << "Materia learned 3: " << materia2->getLearnedMateria(3)->getType() << std::endl;
    std::cout << std::endl;

    materia2->learnMateria(new Ice());
    std::cout << std::endl;

    std::cout << "-------------- destructors --------------------\n\n";

    delete(materia2);
    std::cout << std::endl;

    std::cout << "-------------- leaks check --------------------\n\n";

    atexit(checkleaks);
}