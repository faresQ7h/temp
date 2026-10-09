#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fract = 8;

Fixed::Fixed() : _val(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _val(n * 256)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _val(roundf(n * 256))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _val(other._val)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_val = other._val;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_val;
}

void Fixed::setRawBits( int const raw )
{
    this->_val = raw;
}

float Fixed::toFloat( void ) const
{
    return (static_cast<float>(this->_val) / 256);
}
