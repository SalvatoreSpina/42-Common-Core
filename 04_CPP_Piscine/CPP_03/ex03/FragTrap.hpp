#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

using std::string;

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const string& name);
    FragTrap(const FragTrap& other);
    
    FragTrap& operator=(const FragTrap& other);

    void attack(const string& target);
    void highFivesGuys(void);

    virtual ~FragTrap();
};

#endif