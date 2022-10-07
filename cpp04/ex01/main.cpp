#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void copyTesting(void)
{
	std::cout << "--------Copy Testing-------------\n" << std::endl;

	Dog A;
	Dog B;
	std::cout << std::endl;
	
    A.printDogIdeas();
	std::cout << std::endl;
	std::cout << std::endl;
	
    B.printDogIdeas();
	std::cout << std::endl;
	std::cout << std::endl;
	
    B = A;
	A.printDogIdeas();
	std::cout << std::endl;
	std::cout << std::endl;
	
    B.printDogIdeas();
	std::cout << std::endl;
	std::cout << std::endl;

	Cat C;
	Cat D(C);
	std::cout << std::endl;
	std::cout << std::endl;

	C.printCatIdeas();
	std::cout << std::endl;
	std::cout << std::endl;

	D.printCatIdeas();
	std::cout << std::endl;
	std::cout << std::endl;
}

void arrayTesting(void)
{
	std::cout << "------Array Testing------------\n" << std::endl;

	Animal *array[4];

    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            array[i] = new Cat();
        else
            array[i] = new Dog();
    }
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete (array[i]);
}

void generalTesting(void)
{
	std::cout << "------General Testing-----------\n" << std::endl;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* k = new Dog();
	std::cout << std::endl;

	std::cout << "type: " << j->getType() << " " << std::endl;
	std::cout << "type: " << i->getType() << " " << std::endl;
	std::cout << "type: " << k->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	k->makeSound();
	std::cout << std::endl;

	delete j;
	delete i;
	delete k;
}

int main()
{
	generalTesting();
	std::cout << std::endl;
	arrayTesting();
	std::cout << std::endl;
	copyTesting();

    system("leaks -q animal");
	return (0);
}