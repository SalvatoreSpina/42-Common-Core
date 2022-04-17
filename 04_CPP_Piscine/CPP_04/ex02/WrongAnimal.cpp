#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
        type = "Wrong Animal";
        cout << type << " is born" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
        *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
        this->type = copy.getType();
        return *this;
}

WrongAnimal::~WrongAnimal()
{
        cout << type << " is dead" << endl;
}

string const &WrongAnimal::getType() const
{
        return (this->type);
}

void WrongAnimal::makeSound() const
{
        cout << "* WHALE CRY *" << endl;
}