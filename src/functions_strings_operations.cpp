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
        if (distribution_file() == "Raspbian GNU/Linux")
        {
            output = "\033[1;31m";
            return output;
        }
        else
        {
            return "\e[1m";
        }
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
        if (distribution_file() == "Raspbian")
        {
            return "\033[0m";
        }
        else
        {
            return "\e[0m";
        }
    }
    else
    {
        return "\033[0m";
    }
}

string int_to_str(int n)
{
     string tmp, ret;
     if(n < 0) {
      ret = "-";
      n = -n;
     }
     do {
      tmp += n % 10 + 48;
      n -= n % 10;
     }
     while(n /= 10);
     for(int i = tmp.size()-1; i >= 0; i--)
      ret += tmp[i];
     return ret;
}