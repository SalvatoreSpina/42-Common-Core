#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>
#include <string>

using std::ostream;
using std::cout;
using std::endl;
using std::string;

template <typename T>
void iter(T *lst, size_t len, void (*f)(T &))
{
    for (size_t i = 0; i < len; i++)
        f(lst[i]);
}

#endif 