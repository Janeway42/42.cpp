#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void copyTesting(void)
{
	std::cout << "----Copy Testing----" << std::endl;
	std::cout << std::endl;

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

}

void arrayTesting(void)
{
	std::cout << "----Array Testing----" << std::endl;
	std::cout << std::endl;

	Animal *array[4];

	for (int i = 0; i < 2; i++)
		array[i] = new Cat("Cat");
	for (int i = 2; i < 4; i++)
		array[i] = new Dog("Dog");

	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete (array[i]);
}

void generalTesting(void)
{
	std::cout << "----General Testing----" << std::endl;
	std::cout << std::endl;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* k = new Dog("Elephant");
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
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

	return (0);
}