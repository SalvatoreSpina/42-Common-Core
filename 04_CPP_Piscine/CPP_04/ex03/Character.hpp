#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	string _name;
	AMateria *_materia[4];

	Character(){};

public:
	Character(string const &name);
	Character(Character const &other);
	Character &operator=(Character const &other);
	~Character();

	string const &getName() const;
	AMateria const *getMateria(int index) const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif