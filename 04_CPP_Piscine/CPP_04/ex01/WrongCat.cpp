#include "WrongCat.hpp"

WrongCat::WrongCat()
{
        type = "Wrong Cat";
        cout << type << " is born" << endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
        *this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
        this->WrongAnimal::operator=(other);
        return (*this);
}

WrongCat::~WrongCat()
{
        cout << type << " is dead" << endl;
}

void WrongCat::makeSound() const
{
        cout << "Meow!!" << endl;
}
