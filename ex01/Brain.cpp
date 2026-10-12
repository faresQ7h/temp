#include "Brain.hpp"

// Canonical form
Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "";
    }
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

// Ideas management
void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    } else {
        std::cerr << "Index out of bounds when setting idea" << std::endl;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    } else {
        std::cerr << "Index out of bounds when getting idea" << std::endl;
        return "";
    }
}
