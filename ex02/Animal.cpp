#include "Animal.hpp"

// Cononical form
Animal::Animal() : type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

// Member functions
std::string Animal::getType() const {
    return type;
}

// void Animal::makeSound() const {
//     std::cout << "Animal makes a sound" << std::endl;
// }

// void Animal::printInfo() const {
//     std::cout << "Animal type: " << type << std::endl;
// }

