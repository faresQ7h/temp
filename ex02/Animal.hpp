#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    std::string getType() const;

    // pure virtual = abstract (not complete class body)
    virtual void makeSound() const = 0;
    virtual void printInfo() const = 0;
};

#endif // ANIMAL_HPP
