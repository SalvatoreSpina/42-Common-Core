#include "sed.hpp"

void error_message(string error_message)
{
    cerr << error_message << endl;
    exit(1);
}

void file_to_string(const string& file_name, string& dest)
{
    char c;

    ifstream input_file(file_name);
    if (!input_file)
        error_message("Failed to open");
    while (input_file.get(c))
        dest += c;
    if (!input_file.eof())
        error_message("Failed to read");
}

void string_to_file(const string& file_name, const string& str)
{
    ofstream ofs(file_name);
    if (!ofs)
        error_message("Failed to open");
    ofs << str;
    if (ofs.fail())
        error_message("Failed to write");
}

string replace_string(const string s1,
                           const string s2,
                           const string& str)
{
    size_t s1_size = s1.length();
    string dst;

    std::string::size_type before_pos = 0;
    std::string::size_type pos = str.find(s1);
    while (pos != string::npos)
    {
        dst += str.substr(before_pos, pos - before_pos);
        dst += s2;
        before_pos = pos + s1_size;
        pos = str.find(s1, before_pos);
    }
    dst += str.substr(before_pos);
    return dst;
}

int main(int argc, char **argv)
{
    string str;

    if (argc != 4)
        error_message("Input three arguments.");
    if (argv[2][0] == '\0' || argv[3][0] == '\0')
        error_message("String can't be empty!");
    string file_name = argv[1];
    file_to_string(file_name, str);
    file_name += ".replace";
    str = replace_string(argv[2], argv[3], str);
    string_to_file(file_name, str);
}