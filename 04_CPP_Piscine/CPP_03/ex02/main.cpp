#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap a;
    cout << "hitPoints: " << a.getHitPoints() << endl;
    cout << "energyPoints: " << a.getEnergyPoints() << endl;
    cout << "attackDamage: " << a.getAttackDamage() << endl;
    a.takeDamage(3);
    FragTrap b(a);
    b.takeDamage(3);
    FragTrap c;
    c = b;
    b.takeDamage(3);

    FragTrap d("crap");
    d.attack("tag");
    d.takeDamage(4);
    d.beRepaired(10);
    d.highFivesGuys();
}
