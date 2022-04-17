#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <climits>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;

class Fixed
{
private:
    static const int fractionalBits = 8;
    int value;

public:
    Fixed();
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed& other);
    ~Fixed();

    Fixed& operator=(const Fixed& other);

    int getRawBits(void) const;
    void setRawBits(const int value);

    float toFloat(void) const;
    int toInt(void) const;
};

ostream& operator<<(ostream& os, const Fixed &other);

#endif