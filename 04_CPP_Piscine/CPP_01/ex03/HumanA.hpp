#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class HumanA 
{
private:
	string name;
    Weapon& weapon;

public:
	HumanA(string name, Weapon& weapon);
	void attack() const;
};

#endif