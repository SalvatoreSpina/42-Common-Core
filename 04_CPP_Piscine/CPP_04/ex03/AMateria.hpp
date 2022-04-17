#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

using std::string;

class AMateria
{
private:
	AMateria(){};

protected:
	string _type;
	unsigned int _xp;

public:
	AMateria(string const &type);
	AMateria(AMateria const &other);
	AMateria &operator=(AMateria const &other);
	virtual ~AMateria();
	string const &getType() const;	//Returns the materia type
	unsigned int getXP() const;		//Returns the Materia's XP
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif