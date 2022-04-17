#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombie;

    if (N < 0)
        return (NULL);
    zombie = new Zombie[N];
    while (N--)
        zombie[N].set_name(name);
    return zombie;
}