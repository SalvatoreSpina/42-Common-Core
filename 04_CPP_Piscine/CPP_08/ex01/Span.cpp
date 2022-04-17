#include "Span.hpp"

Span::Span()
{
    _size = 0;
};

Span::Span(unsigned int n)
{
    _size = n;
}

Span::Span(Span const &other)
{
    _size = other.size();
    _values = other.getValues();
}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        _size = other.size();
        _values = other.getValues();
    }
    return *this;
}

Span::~Span()
{
}

unsigned int Span::size() const
{
    return _size;
}

vector<int> const &Span::getValues() const
{
    return _values;
}

void Span::addNumber(int n)
{
    if (_values.size() >= _size)
        throw Span::FullException();
    _values.push_back(n);
}

void Span::addNumber(vector<int>::iterator const &begin, vector<int>::iterator const &end)
{
    int size = distance(begin, end);
    if (size > static_cast<int>(_size))
        throw Span::FullException();
    _values.insert(_values.end(), begin, end);
}

long Span::shortestSpan() const
{
    if (_values.size() < 2)
        throw Span::CantSearchException();
    vector<int> copy = _values;

    sort(copy.begin(), copy.end());
    vector<int>::iterator prev_it = copy.begin();
    vector<int>::iterator next_it = ++copy.begin();
    long minSpan = *next_it - *prev_it;

    while (next_it != copy.end())
    {
        if ((long)*next_it - *prev_it < minSpan)
            minSpan = (long)*next_it - *prev_it;
        prev_it = next_it;
        next_it++;
    }
    return minSpan;
}

long Span::longestSpan() const
{
    if (_values.size() < 2)
        throw Span::CantSearchException();
    vector<int> copy = _values;

    sort(copy.begin(), copy.end());

    return ((long)copy.back() - copy.front());
}