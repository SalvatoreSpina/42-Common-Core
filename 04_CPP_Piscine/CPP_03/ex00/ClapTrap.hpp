#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class ClapTrap
{
private:
	string			name;
	int				hitPoints;
	int				energyPoints;
	unsigned int	attackDamage;

public:
	ClapTrap ();
	ClapTrap(const string &name);
	ClapTrap(const ClapTrap &a);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &a);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif