#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::exception;
using std::vector;
using std::cerr;

class Span
{
private:
    unsigned int _size;
    vector<int> _values;
    Span();

public:
    Span(unsigned int n);
    Span(Span const &other);
    Span &operator=(Span const &other);
    int &operator[](int i);
    ~Span();

    unsigned int size() const;
    vector<int> const &getValues() const;

    void addNumber(int n);
    void addNumber(vector<int>::iterator const &, vector<int>::iterator const &);
    long shortestSpan() const;
    long longestSpan() const;

    class OutOfRangeException : public exception
    {
    public:
        const char *what() const throw()
        {
        return ("Out of range");
        }
    };
    class FullException : public exception
    {
    public:
        const char *what() const throw()
        {
        return ("Buffer is already full");
        }
    };
    class CantSearchException : public exception
    {
    public:
        const char *what() const throw()
        {
        return ("Can't search");
        }
    };
};