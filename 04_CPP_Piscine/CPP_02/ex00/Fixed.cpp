#include "Fixed.hpp"

Fixed::Fixed()
{
    cout << "Default constructor called" << endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    cout << "Copy constructor called" << endl;
    *this = other;
}

Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    cout << "Assignation operator called" << endl;
    value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    cout << "getRawBits called" << endl;
    return this->value;
}

void Fixed::setRawBits(const int raw)
{
    cout << "setRawBits called" << endl;
    this->value = raw;
}