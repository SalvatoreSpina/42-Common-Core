#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
	cout << "DiamondTrap (void)" << endl;
	this->name = "default";
	this->FragTrap::hitPoints = 100;
	this->ScavTrap::energyPoints = 50;
	this->FragTrap::attackDamage = 30;
}
DiamondTrap::DiamondTrap(string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	cout << "DiamondTrap (" << name << ")" << endl;
	this->name = name;
	this->FragTrap::hitPoints = 100;
	this->ScavTrap::energyPoints = 50;
	this->FragTrap::attackDamage = 30;
}

void DiamondTrap::attack(string const &target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	cout << "My name is " << ClapTrap::getName() << endl;
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap (" << this->name << ") was destroyed!" << endl;
}