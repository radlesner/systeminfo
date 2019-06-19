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