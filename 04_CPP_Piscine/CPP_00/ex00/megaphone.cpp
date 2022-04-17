#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::toupper;
using std::size_t;

int main (int argc, char **argv) {
    
    if (argc == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
    else 
    {
        string print;
        
        for (int i = 1; i < argc; i++)
        {
            string str = argv[i];
            for (size_t j = 0; j < str.length(); j++)
                str[j] = toupper(str[j]);
            print += str;
                if (i != argc - 1)
                    print += " ";
        }
        cout << print << endl;
        return 0;
    }
}