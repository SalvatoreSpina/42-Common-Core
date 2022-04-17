#include "iter.hpp"

void print_string(string &str)
{
    cout << str << endl;
}

void print_int(int &ints)
{
    cout << ints << endl;
}

int main(void)
{
    cout << "Let's print an array of string" << endl;
    string str[] = {"Hello", "World", "achansel", "42NICE"};
    iter(str, sizeof(str) / sizeof(string), print_string);

    cout << "\nAnd now an array of int" << endl;
    int ints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    iter(ints, sizeof(ints) / sizeof(int), print_int);
    
    return (0);
}