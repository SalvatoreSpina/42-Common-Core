#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class HumanB 
{
private:
	string name;
    Weapon* weapon;

public:
	HumanB(string name);
    void setWeapon(Weapon& weapon);
	void attack() const;
};

#endif