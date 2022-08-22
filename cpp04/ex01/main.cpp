#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	const WrongAnimal* beta = new WrongAnimal();
	const Animal* k = new Dog();
	const WrongAnimal* l = new WrongCat();

	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	k->makeSound(); 
	l->makeSound();
	beta->makeSound();
	std::cout << std::endl;

	delete (meta);
	delete (j);
	delete(i);
	delete(beta);
	delete(k);
	delete(l);
	return (0);
}