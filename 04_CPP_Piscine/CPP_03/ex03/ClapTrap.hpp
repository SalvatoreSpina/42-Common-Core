#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class ClapTrap
{
protected:
	string name;
	int hitPoints;
	int energyPoints;
	unsigned int attackDamage;

public:
	ClapTrap();
	ClapTrap(const string &name);

	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);

	void attack(string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	unsigned int getAttackDamage() const;

	void setHitPoints(int hitPoints);
	void setEnergyPoints(int energyPoints);
	void setAttackDamage(unsigned int attackDamage);

	virtual ~ClapTrap();
};

#endif