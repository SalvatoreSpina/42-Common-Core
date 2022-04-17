#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

typedef struct
{
    int     age;
    string  name;
} Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif