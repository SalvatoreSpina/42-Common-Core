#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define MAX 8

#include "Contact.hpp"
#include <iomanip>
#include <cstring>

using std::cin;
using std::getline;
using std::setw;
using std::right;
using std::exit;

class PhoneBook
{
private:
    Contact cot[8];
    int current_i;

    void put_one(string str) const;
    void put_contact_list() const;
    string input_one(string put_string) const;
    void add_command();
    void search_command() const;

public:
    PhoneBook();
    void loop();
};

#endif