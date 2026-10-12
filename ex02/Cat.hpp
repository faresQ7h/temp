#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;

public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    // Actions
    virtual void makeSound() const;
    virtual void printInfo() const;

    //Getters
    Brain* getBrain() const;
};
#endif // CAT_HPP
