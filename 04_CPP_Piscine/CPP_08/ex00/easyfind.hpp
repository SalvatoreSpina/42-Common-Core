#pragma once

#include <iterator>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::exception;
using std::vector;
using std::find;

class OutOfRangeException : public exception
{
public:
    const char *what() const throw()
    {
        return "Out of range";
    }
};

template <class T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = find(container.begin(), container.end(), value);
    if (it == container.end())
        throw OutOfRangeException();
    return it;
};