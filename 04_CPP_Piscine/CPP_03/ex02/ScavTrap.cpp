#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	cout << "ScavTrap (void)" << endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(string const &name) : ClapTrap(name)
{
	cout << "ScavTrap (" << name << ")" << endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other)
{
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	ClapTrap::operator=(other);
	return (*this);
}


void ScavTrap::attack(string const &target)
{
	cout << "ScavTrap::";
	this->ClapTrap::attack(target);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	cout << "ScavTrap::";
	this->ClapTrap::takeDamage(amount);
}

void ScavTrap::beRepaired(unsigned int amount)
{
	cout << "ScavTrap::";
	this->ClapTrap::beRepaired(amount);
}

void ScavTrap::guardGate()
{
	cout << "Gate keeper mode active" << endl;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap (" << this->getName() << ") was destroyed!" << endl;
}
