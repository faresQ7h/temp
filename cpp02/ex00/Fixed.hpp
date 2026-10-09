#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _val;
        static const int _fract; //fraction bits

    public:
        Fixed();
        Fixed(const Fixed& other); //the copy constructor
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif
