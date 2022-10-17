#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
    std::cout << std::endl;

	std::cout << "type: " << j->getType() << " " << std::endl;
	std::cout << "type: " << i->getType() << " " << std::endl;
	std::cout << "type: " << meta->getType() << " " << std::endl;

	j->makeSound(); 
	i->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete (meta);
	delete (i);
	delete(j);
	std::cout << std::endl;

	const WrongAnimal* beta = new WrongAnimal();
	const WrongAnimal* l = new WrongCat();
    std::cout << std::endl;

	std::cout << "type: " << l->getType() << " " << std::endl;
	std::cout << "type: " << beta->getType() << " " << std::endl;

	l->makeSound();
	beta->makeSound();
	std::cout << std::endl;

	delete(beta);
	delete(l);

	return (0);
}