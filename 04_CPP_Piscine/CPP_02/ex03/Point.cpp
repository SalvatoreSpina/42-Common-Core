#include "Point.hpp"

Point::Point(void)
	: x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(const float x, const float y)
	: x(Fixed(x)), y(Fixed(y))
{
}

Point::Point(const Point& copy)
	: x(copy.x), y(copy.y)
{
}

Point::~Point(void)
{
}

Point& Point::operator=(const Point& other)
{
	(void)other;
	cout << "Assignment of const variables impossible, values will stay the same as in the default constructor." << endl;
	return *this;
}

Fixed const Point::getX(void) const
{
	return this->x;
}

Fixed const Point::getY(void) const
{
	return this->y;
}
