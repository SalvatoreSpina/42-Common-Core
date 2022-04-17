#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_materia[4];

public:
    MateriaSource();
    MateriaSource(MateriaSource const &other);
    MateriaSource &operator=(MateriaSource const &other);
    AMateria *getMateria(int index) const;
    ~MateriaSource();

    void learnMateria(AMateria *materia);
    AMateria *createMateria(std::string const &type);
};

#endif 