#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
	: value(0)
{
}

Fixed::Fixed(int const val)
	: value(val << rawBits)
{
}

Fixed::Fixed(float const val)
	: value(int(roundf(val * (1 << rawBits))))
{
}

Fixed::Fixed(const Fixed& fixed)
	: value(fixed.value)
{
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->value = other.value;
	return *this;
}

bool Fixed::operator>(const Fixed& other)
{
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other)
{
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other)
{
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other)
{
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other)
{
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other)
{
	return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed& other)
{
	return Fixed(this->value + other.value);
}

Fixed Fixed::operator-(const Fixed& other)
{
	return Fixed(this->value - other.value);
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed ret;

	ret.setRawBits(this->value * other.value >> rawBits);
	return ret;
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed ret;

	ret.setRawBits(this->value / other.value << rawBits);
	return ret;
}

Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return tmp;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return float(this->value) / (1 << rawBits);
}

int Fixed::toInt(void) const
{
	return this->value >> rawBits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return b;
	return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return b;
	return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.value > b.value)
		return b;
	return a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.value < b.value)
		return b;
	return a;
}

std::ostream& operator<<(ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}