#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *zombie;

    return zombie = new Zombie(name);
}