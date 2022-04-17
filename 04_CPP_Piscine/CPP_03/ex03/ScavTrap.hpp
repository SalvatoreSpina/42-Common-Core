#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

using std::string;
using std::cout;
using std::endl;

class ScavTrap : virtual public ClapTrap
{
private:
	

public:
	ScavTrap();
	ScavTrap(string const &name);
	ScavTrap(ScavTrap const &other);

	ScavTrap &operator=(ScavTrap const &other);
	
	void attack(string const &target);
	void guardGate();

	virtual ~ScavTrap();
};

#endif
