#include "Fixed.hpp"

Fixed::Fixed()
{
    cout << "Default constructor called" << endl;
    this ->value = 0;
}

Fixed::Fixed(int value)
{
    cout << "Int constructor called" << endl;
	this->value = value << this->fractionalBits;
}

Fixed::Fixed(float value)
{
    cout << "Float constructor called" << endl;
    this->value = (int)(roundf(value * (1 << fractionalBits)));
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

int Fixed::toInt(void) const
{
    return (this->value >> this->fractionalBits);
}

float Fixed::toFloat(void) const
{
    return ((float)this->value / (1 << this->fractionalBits));
}

int Fixed::getRawBits(void) const
{
    cout << "getRawBits called" << endl;
    return (this->value);
}

void Fixed::setRawBits(int raw)
{
    cout << "setRawBits called" << endl;
    this->value = raw;
}

ostream& operator<<(ostream& os, const Fixed &other)
{
    os << other.toFloat();
    return os;
}