#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	cout << "ClapTrap::ClapTrap (void)" << endl;
	this->name = "default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(string const &name)
{
	cout << "ClapTrap::ClapTrap (" << name << ")" << endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	cout << "ClapTrap::ClapTrap(other)" << endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	cout << "ClapTrap::operator=(other)" << endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

void ClapTrap::attack(string const &target)
{
    if ((this->hitPoints > 0) && (this->energyPoints > 0))
    {
        cout << "ClapTrap " << this->name << " attacks "
                          << target << ", causing " << this->attackDamage
                          << " points of damage!" << endl;
        this->energyPoints -= 1;
        if (this->energyPoints <= 0)
                this->energyPoints = 0;
    }
    else
        cout << "ClapTrap " << this->name << "has no energy or health!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
        cout << this->name << " take " << amount << " damage!" << endl;
        this->hitPoints -= amount;
        if (this->hitPoints <= 0)
                this->hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if ((this->hitPoints > 0) && (this->energyPoints > 0))
    {
        cout << this->name << " be repaired " << amount << " hit points!" << endl;
        this->hitPoints += amount;
        this->energyPoints -= 1;
        if (this->energyPoints <= 0)
                this->energyPoints = 0;
    }
    else
        cout << "ClapTrap " << this->name << "has no energy or health!" << endl;
}

string ClapTrap::getName() const
{
	return this->name;
}

int ClapTrap::getHitPoints() const
{
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return this->energyPoints;
}
unsigned int ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->attackDamage = attackDamage;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap (" << this->name << ") was destroyed!" << endl;
}
