#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl Harl;

    if (argc != 2)
    {
        cerr << "One argument is required" << endl;
        exit(1);
    }
    string str = argv[1];
    string level_list[MAX_LVL] = {
        "DEBUG", 
        "INFO", 
        "WARNING", 
        "ERROR"};
    int level = MAX_LVL;
    for (int i = 0; i < MAX_LVL; i++)
    {
        if (str == level_list[i])
        {
            level = i;
            break;
        }
    }
    switch (level)
    {
        case DEBUG:
            cout << "[ DEBUG ]\n";
            Harl.complain("DEBUG");
            cout << endl;
        case INFO:
            cout << "[ INFO ]\n";
            Harl.complain("INFO");
            cout << endl;
        case WARNING:
            cout << "[ WARNING ]\n";
            Harl.complain("WARNING");
            cout << endl;
        case ERROR:
            cout << "[ ERROR ]\n";
            Harl.complain("ERROR");
            cout << endl;
            break;
        case MAX_LVL:
            cout << "[ Probably complaining about insignificant problems ]" << endl;
    }
}