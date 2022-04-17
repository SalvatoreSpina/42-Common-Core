#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string str = "HI THIS IS BRAIN";
    string *stringPTR = &str;
    string &stringREF = str;

    cout << "str addres: " << &str << endl;
    cout << "stringPTR addres: " << stringPTR << endl;
    cout << "stringREF addres: " << &stringREF << endl;

    cout << "string variable: " << str << endl;
    cout << "stringPTR: " << *stringPTR << endl;
    cout << "stringREF: " << stringREF << endl;

}