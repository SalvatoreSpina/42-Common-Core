#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	cout << "Creating Materias..." << endl;
	IMateriaSource *cluster = new MateriaSource();
	cluster->learnMateria(new Ice());
	cluster->learnMateria(new Cure());

	cout << "\nCreating Character..." << endl;
	ICharacter *sasso = new Character("sasso");
	AMateria *tmp;
	tmp = cluster->createMateria("ice");
	sasso->equip(tmp);
	tmp = cluster->createMateria("cure");
	sasso->equip(tmp);
	ICharacter *achansel = new Character("achansel");
	sasso->use(0, *achansel);
	sasso->use(1, *achansel);

	cout << "\nDestroying..." << endl;
	delete achansel;
	delete sasso;
	delete cluster;

	system("leaks 42_fantasy");

	return 0;
}