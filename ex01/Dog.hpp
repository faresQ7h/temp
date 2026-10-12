#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;

public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    // Actions
    virtual void makeSound() const;
    virtual void printInfo() const;
    
    // Getters
    Brain* getBrain() const;
};

#endif // DOG_HPP
