#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string type;

public:
    //Canonical Form
    AMateria();
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    ~AMateria();

    //Constructor with type parameter
    AMateria(std::string const & type);

    //Getter
    std::string const & getType() const; //Returns the materia type

    // Actions
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif //AMATERIA_HPP