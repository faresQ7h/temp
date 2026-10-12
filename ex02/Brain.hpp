#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100];

public:
    //Cononical form
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    // Ideas management
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif // BRAIN_HPP
