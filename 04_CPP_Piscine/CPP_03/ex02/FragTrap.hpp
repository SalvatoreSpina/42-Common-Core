#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

using std::string;

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(const string& name);
    FragTrap(const FragTrap& other);
    virtual ~FragTrap();

    FragTrap& operator=(const FragTrap& other);

    void attack(const string& target);
    void highFivesGuys(void);
};

#endif