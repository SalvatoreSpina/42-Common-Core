#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Animal
{
protected:
    string type;

public:
    Animal();
	Animal(string type);
	Animal(Animal const &);
	Animal &operator=(Animal const &);
	virtual ~Animal();

	string const &getType() const;
	virtual void makeSound() const;
};

#endif