#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
    Zombie *zombie;
    string str;

    str = "test_newZombie";
    zombie = newZombie(str);
    zombie->announce();
    str = "test_randomChump";
    randomChump(str);
    delete zombie;
}