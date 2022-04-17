#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    cout << "FragTrap default constructor called" << endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const string& name)
{
    cout << "FragTrap constructor called" << endl;
    this->name = name;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
{
    cout << "FragTrap copy constructor called" << endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    cout << "FragTrap destructor of " << name << " called" << endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    name = other.getName();
    hitPoints = other.getHitPoints();
    energyPoints = other.getEnergyPoints();
    attackDamage = other.getAttackDamage();
    return *this;
}

void FragTrap::attack(const string& target)
{
    cout << "FragTrap " << name << \
                 " attacks " << target << \
                 ", causing " << attackDamage << \
                 " points of damage!" << endl;
}

void FragTrap::highFivesGuys()
{
    cout << "FragTrap " << name << " said: I'M FRAG CLAP AT ME" << endl;
}