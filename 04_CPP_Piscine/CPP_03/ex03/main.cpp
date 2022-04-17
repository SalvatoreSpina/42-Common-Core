#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap achansel("Achansel");

	achansel.attack("Minishell!");
	achansel.takeDamage(100);
	achansel.beRepaired(3);
	achansel.highFivesGuys();
	achansel.guardGate();
	achansel.whoAmI();
}