#include "Dog.hpp"

// Canonical form
Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

// Member functions
void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

void Dog::printInfo() const {
    std::cout << "Dog type: " << type << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}
