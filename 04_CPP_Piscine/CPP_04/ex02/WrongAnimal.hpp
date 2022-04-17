#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class WrongAnimal
{
protected:
    string type;

public:
    WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal &operator=(const WrongAnimal &copy);
	virtual ~WrongAnimal();

	string const &getType() const;
	void makeSound() const;
};

#endif