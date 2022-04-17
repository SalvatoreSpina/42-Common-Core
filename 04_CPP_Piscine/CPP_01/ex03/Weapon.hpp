#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

using std::string;

class Weapon
{
private:
	string type;

public:
	Weapon();
	Weapon(string type);
	const string& getType() const;
	void setType(string type);
};

#endif