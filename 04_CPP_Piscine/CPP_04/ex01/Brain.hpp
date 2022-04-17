#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Brain
{
private:
    string ideas[100];

public:
    Brain();
	Brain(Brain const &other);
	Brain &operator=(Brain const &other);
	~Brain();

	string const &getIdea(int index) const;
};

#endif