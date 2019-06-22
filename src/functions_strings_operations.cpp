#include "functions_strings_operations.h"

using namespace std;

string switch_words(string value)
{
    for (int i = 1; i < value.length(); i++)
    {
        value[i] = tolower(value[i]);
    }

    return value;
}

string bold_text_start()
{
    return "\e[1m";
}

string bold_text_end()
{
    return "\e[0m";
}