#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <climits>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Fixed
{
private:
    static const int fractionalBits = 8;
    int value;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(const int value);
};

#endif
