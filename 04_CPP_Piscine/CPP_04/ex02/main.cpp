#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *Animals[10];
    cout << "Creating animals..." << endl;
    for (int i = 0; i < 10; ++i)
    {
        if (i % 2 == 0)
            Animals[i] = new Dog();
        else
            Animals[i] = new Cat();
        cout << endl;
    }

    cout << "\nTesting copies..." << endl;
    Dog copy(*(Dog *)Animals[0]);
    for (int i = 0; i < 100; ++i)
    {
        cout << copy.getBrain()->getIdea(i) << endl;
        cout << ((Dog *)Animals[0])->getBrain()->getIdea(i) << endl;
    }

    cout << "\nKilling animals..." << endl;
    for (int i = 0; i < 10; ++i)
    {
        delete Animals[i];
        cout << endl;
    }
}