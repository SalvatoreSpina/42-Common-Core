#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

using std::string;
using std::cout;
using std::endl;

class ScavTrap : public ClapTrap
{
private:
	ScavTrap();

public:
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &other);

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ScavTrap &operator=(ScavTrap const &other);

	void guardGate();

	~ScavTrap();
};

#endif
