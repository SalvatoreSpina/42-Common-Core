#include <iostream>
#include <string>
#include <vector>
#include "Span.hpp"

int main(void)
{
    {
        cout << "Test Span 5:" << endl;
        Span sp = Span(5);

        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        cout << sp.shortestSpan() << endl;
        cout << sp.longestSpan() << endl;
    }
    {
        cout << "Test exception on empty vector:" << endl;
        Span sp = Span(5);

        try
        {
            sp.shortestSpan();
        }
        catch (exception &e)
        {
            cerr << e.what() << endl;
        }
        try
        {
            sp.longestSpan();
        }
        catch (exception &e)
        {
            cerr << e.what() << endl;
        }

        sp.addNumber(1);

        cout << "And the same on a single element vector:" << endl;
        try
        {
            sp.shortestSpan();
        }
        catch (exception &e)
        {
            cerr << e.what() << endl;
        }
        try
        {
            sp.longestSpan();
        }
        catch (exception &e)
        {
            cerr << e.what() << endl;
        }

        cout << "And now a size overflow:" << endl;
        try
        {
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4);
            sp.addNumber(5);
            sp.addNumber(6);
        }
        catch (exception &e)
        {
            cerr << e.what() << endl;
        }
    }
    {
        cout << "And the 10'000 test they asked for:" << endl;

        Span sp(10000);

        vector<int> vec;
        for (int i = 0; i < 10000; i++)
            vec.push_back(i + 1);
        sp.addNumber(vec.begin(), vec.end());

        cout << sp.shortestSpan() << endl;
        cout << sp.longestSpan() << endl;
    }
    return (0);
}