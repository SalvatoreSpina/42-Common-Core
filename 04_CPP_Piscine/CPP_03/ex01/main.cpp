#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap achansel("Achansel");

	achansel.attack("minishell");
	achansel.takeDamage(100);
	achansel.beRepaired(3);
	achansel.guardGate();
}
