#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : current_i(0) {}

void PhoneBook::put_one(string str) const
{
    size_t len = str.length();

    if (len <= 10)
        cout << setw(10) << right << str;
    else
        cout << str.substr(0, 9) << ".";
}

void PhoneBook::put_contact_list() const
{
    int i = 0;

    cout << "     index|first name| last name|  nickname" << endl;
    while (i < MAX && !cot[i].is_empty())
    {
        cout << setw(10) << right << i << "|";
        put_one(cot[i].get_first_name());
        cout << "|";
        put_one(cot[i].get_last_name());
        cout << "|";
        put_one(cot[i].get_nickname());
        cout << "\n" << endl;
        i++;
    }
}

string PhoneBook::input_one(string put_string) const
{
    string str;

    while (str.empty())
    {
        cout << put_string << endl;
        if (getline(cin, str).eof())
            exit(0);
    }
    return str;
}

void PhoneBook::add_command()
{
    string first_name;
    string last_name;
    string nickname;
    string phone_number;
    string darkest_secret;

    cout << "\033[32mEnter new contact information\033[0m" << endl;
    first_name = input_one("\033[32mEnter first name\033[0m");
    last_name = input_one("\033[32mEnter last name\033[0m");
    nickname = input_one("\033[32mEnter nickname\033[0m");
    phone_number = input_one("\033[32mEnter phone number\033[0m");
    darkest_secret = input_one("\033[32mEnter darkest secret\033[0m");
    cot[current_i].set_contact(first_name,
                               last_name,
                               nickname,
                               phone_number,
                               darkest_secret);
    current_i = (current_i + 1) % MAX;
    cout << "\033[32mRegistration is complete\n\033[0m" << endl;
}

void PhoneBook::search_command() const
{
    if (cot[0].is_empty())
    {
        cout << "\033[31mThere are no contacts to display\n\033[0m" << endl;
        return ;
    }

    put_contact_list();

    while (true)
    {
        string str;

        cout << "\033[32mEnter an index\033[0m" << endl;
        if (getline(cin, str).eof())
            exit(0);
        if (str.length() == 1 && '0' <= str[0] && 
			str[0] <= '7' && !cot[str[0] - '0'].is_empty())
        {
            cot[str[0] - '0'].put_contact();
            cout << endl;
            break;
        }
        else
            cout << "\033[31mInvalid input" << endl;
    }
}

void PhoneBook::loop()
{
    cout << "\033[32mADD: Add a contact\033[0m" << endl;
    cout << "\033[32mSEARCH: Display a contact\033[0m" << endl;
    cout << "\033[32mEXIT: Exit the program\n\033[0m" << endl;
    while (true)
    {
        string command;

        cout << "\033[32mEnter the command\033[0m" << endl;
        if (getline(cin, command).eof())
            exit(0);
        if (command == "ADD")
            add_command();
        else if (command == "SEARCH")
            search_command();
        else if (command == "EXIT")
            break;
    }
}