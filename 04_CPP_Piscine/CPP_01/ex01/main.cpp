#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main() 
{
    Zombie *zombie;
    string str;
    int number = 5;

    str = "test_5_zombies";
    zombie = zombieHorde(number, str);
    for (int i = 0; i < number; i++)
        zombie[i].announce();
    delete[] zombie;
}
