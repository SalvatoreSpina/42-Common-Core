#pragma once

#include <iostream>
#include <stack>
#include <algorithm>
#include <list>

using std::cout;
using std::endl;
using std::exception;
using std::vector;
using std::cerr;
using std::list;

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(MutantStack const &other);
    ~MutantStack();

    MutantStack<T> &operator=(MutantStack<T> const &other);

    typedef typename MutantStack<T>::stack::container_type::iterator iterator;
    iterator begin();
    iterator end();

    typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
    const_iterator cbegin() const;
    const_iterator cend() const;

    typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin();
    reverse_iterator rend();

    typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
};