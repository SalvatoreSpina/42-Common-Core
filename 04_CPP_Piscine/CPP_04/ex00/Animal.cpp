#include "Animal.hpp"

Animal::Animal()
{
	this->type = "A GAINT WHALE WHOOOOO";
	cout << "Born " << this->type << endl;
}

Animal::Animal(string type)
{
	this->type = type;
	cout << "Born " << this->type << endl;
}

Animal::Animal(Animal const &other)
{
	*this = other;
}

Animal &Animal::operator=(Animal const &other)
{
	this->type = other.getType();
	return (*this);
}

Animal::~Animal()
{
	cout << "Die " << this->type << endl;
}

string const &Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	cout << "* WHALE CRY *" << endl;
}