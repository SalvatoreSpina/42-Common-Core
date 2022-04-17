#include "ClapTrap.hpp"

int main()
{
        ClapTrap achansel("Achansel");

        achansel.attack("minishell");
        achansel.takeDamage(100);
        achansel.attack("minishell fail test");
        achansel.beRepaired(3);
}