#include "functions_strings_operations.h"
#include "functions_file_operations.h"
#include "functions_file.h"

using namespace std;

string switch_words(string value)
{
    for (int i = 1; i < value.length(); i++)
    {
        value[i] = tolower(value[i]);
    }

    return value;
}

string bold()
{
    int nr_line = 1;
    string output;
    string color = open_file(home_path() + "/.systeminfo-files/systeminfo-color.txt", nr_line);

    if (color == "N/A")
    {
        return "\e[1m";
    }
    else
    {
        output = "\033[" + color + "m";
        return output;
    }
}

string bold_end()
{
    int nr_line = 1;
    string color = open_file(home_path() + "/.systeminfo-files/systeminfo-color.txt", nr_line);

    if (color == "N/A")
    {
        return "\e[0m";
    }
    else
    {
        return "\033[0m";
    }
}