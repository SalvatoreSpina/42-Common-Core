#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
        Brain *brain;
public:
        Dog();
        Dog(Dog const &);
        Dog &operator=(Dog const &);
        ~Dog();

        void makeSound() const;
        Brain *getBrain() const;
};

#endif