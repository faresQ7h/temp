#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

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
		delete animals[k];

	std::cout << std::endl << "--- Deep copy ---" << std::endl;
	Dog a;
	a.getBrain()->setIdea(0, "I want a bone");

	Dog b(a);
	b.getBrain()->setIdea(0, "I want to sleep");

	std::cout << "a idea: " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "b idea: " << b.getBrain()->getIdea(0) << std::endl;
	std::cout << "a brain: " << a.getBrain() << std::endl;
	std::cout << "b brain: " << b.getBrain() << std::endl;

	std::cout << std::endl << "--- Deep copy (assignment) ---" << std::endl;
	Cat c;
	c.getBrain()->setIdea(0, "I want fish");

	Cat d;
	d = c;
	d.getBrain()->setIdea(0, "I want to scratch");

	std::cout << "c idea: " << c.getBrain()->getIdea(0) << std::endl;
	std::cout << "d idea: " << d.getBrain()->getIdea(0) << std::endl;
	std::cout << "c brain: " << c.getBrain() << std::endl;
	std::cout << "d brain: " << d.getBrain() << std::endl;

	std::cout << std::endl << "--- End of program ---" << std::endl;
	return 0;
}
