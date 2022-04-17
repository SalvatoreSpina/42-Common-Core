#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cerr;
using std::exception;


class Zombie
{
private:
    string name;

public:
    Zombie();
    Zombie(string name);
    ~Zombie();
    string get_name() const;
    void set_name(string name);
    void announce(void) const;
};

#endif