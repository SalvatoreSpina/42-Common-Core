#include "Zombie.hpp"

Zombie::Zombie() : name("zombie") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
    std::cout << name << " was destructed" << std::endl;
}

std::string Zombie::get_name() const
{
    return name;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

void Zombie::announce( void ) const
{
    cout << name << " BraiiiiiiinnnzzzZ..." << endl;
}