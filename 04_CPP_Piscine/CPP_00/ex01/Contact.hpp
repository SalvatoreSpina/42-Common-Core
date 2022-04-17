#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Contact
{
private:
    string first_name;
    string last_name;
    string nickname;
    string phone_number;
    string darkest_secret;

public:
    void set_contact(string first_name,
                     string last_name,
                     string nickname,
                     string phone_number,
                     string darkest_secret);
    void put_contact() const;
    string get_first_name() const;
    string get_last_name() const;
    string get_nickname() const;
    bool is_empty() const;
};

#endif