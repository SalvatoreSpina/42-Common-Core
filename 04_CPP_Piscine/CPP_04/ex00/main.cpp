#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    cout << "Creating three animals..." << endl;

    const Animal *meta = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    cout << dog->getType() << endl;
    cout << cat->getType() << endl;

    cout << "\nAnd now we test the sounds" << endl;
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();

    cout << "\nAnd now the wrong test..." << endl;
    const WrongAnimal *wrong = new WrongCat();
    wrong->makeSound();

    cout << "\nGoodbye animals!" << endl;
    delete meta;
    delete cat;
    delete dog;
    delete wrong;
    
    return (0);
}