#include "Contact.hpp"

void Contact::set_contact(string first_name,
                          string last_name,
                          string nickname,
                          string phone_number,
                          string darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

void Contact::put_contact() const
{
    cout << "\033[32mfirst name: \033[0m" << this->first_name << endl;
    cout << "\033[32mlast name: \033[0m" << this->last_name << endl;
    cout << "\033[32mnickname: \033[0m" << this->nickname << endl;
    cout << "\033[32mphone number: \033[0m" << this->phone_number << endl;
    cout << "\033[32mdarkest secret: \033[0m" << this->darkest_secret << endl;
}

string Contact::get_first_name() const
{
    return this->first_name;
}

string Contact::get_last_name() const
{
    return this->last_name;
}

string Contact::get_nickname() const
{
    return this->nickname;
}

bool Contact::is_empty() const
{
    return (this->first_name.empty());
}