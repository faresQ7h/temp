#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "--- Subject test ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl << "--- Abstract Animal ---" << std::endl;
	// Animal a;                    // error: Animal is abstract
	// Animal* p = new Animal();    // error: Animal is abstract
	std::cout << "Animal cannot be instantiated (see commented lines in main)" << std::endl;

	std::cout << std::endl << "--- Array of Animals ---" << std::endl;
	const int size = 4;
	Animal* animals[size];
	for (int k = 0; k < size; k++)
	{
		if (k < size / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	for (int k = 0; k < size; k++)
		animals[k]->makeSound();
	for (int k = 0; k < size; k++)
		delete animals[k];

	std::cout << std::endl << "--- Deep copy (copy constructor) ---" << std::endl;
	Dog a;
	a.getBrain()->setIdea(0, "I want a bone");

	Dog b(a);
	b.getBrain()->setIdea(0, "I want to sleep");

	std::cout << "a idea: " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "b idea: " << b.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "--- Deep copy (assignment) ---" << std::endl;
	Cat c;
	c.getBrain()->setIdea(0, "I want fish");

	Cat d;
	d = c;
	d.getBrain()->setIdea(0, "I want to scratch");

	std::cout << "c idea: " << c.getBrain()->getIdea(0) << std::endl;
	std::cout << "d idea: " << d.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "--- End of program ---" << std::endl;
	return 0;
}
