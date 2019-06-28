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
        if (distribution_file() == "Raspbian GNU/Linux" || distribution_file() == "Raspbian")
            return get_color("red");
        if (distribution_file() == "Ubuntu")
            return get_color("yellow");
        else
            return "\033[1m";
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
        return "\033[0m";
    }
    else
    {
        return "\033[0m";
    }
}

string get_color(string color_input)
{
    string color;

    if (color_input == "black")            color = "\033[0m\033[1;30m";
    else if (color_input == "red")         color = "\033[0m\033[1;31m";
    else if (color_input == "green")       color = "\033[0m\033[1;32m";
    else if (color_input == "brown")       color = "\033[0m\033[1;33m";
    else if (color_input == "blue")        color = "\033[0m\033[1;34m";
    else if (color_input == "cyan")        color = "\033[0m\033[1;36m";
    else if (color_input == "purple")      color = "\033[0m\033[1;35m";
    else if (color_input == "yellow")      color = "\033[0m\033[1;33m";
    else if (color_input == "white")       color = "\033[0m\033[1;37m";
    else if (color_input == "grey")        color = "\033[0m\033[37m";
    else if (color_input == "rosa_blue")   color = "\033[01;38;05;25m";
    else                                   color = "\033[0m\033[1;30m";

    return color;
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

void get_logo()
{
    if (distribution_file() == "ManjaroLinux" || distribution_file() == "Manjaro Linux" || distribution_file() == "Manjaro")
    {
        int ter_width = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-ter-size.txt", 2).c_str() );
        string space;

        int count = (ter_width / 2) - (28 / 2);
        for (int i = 0; i < count; i++)
        {
            space += " ";
        }

        cout << space << bold() << "██████████████████  ████████" << bold_end() << endl;
        cout << space << bold() << "██████████████████  ████████" << bold_end() << endl;
        cout << space << bold() << "██████████████████  ████████" << bold_end() << endl;
        cout << space << bold() << "██████████████████  ████████" << bold_end() << endl;
        cout << space << bold() << "████████            ████████" << bold_end() << endl;
        cout << space << bold() << "████████  ████████  ████████" << bold_end() << endl;
        cout << space << bold() << "████████  ████████  ████████" << bold_end() << endl;
        cout << space << bold() << "████████  ████████  ████████" << bold_end() << endl;
        cout << space << bold() << "████████  ████████  ████████" << bold_end() << endl;
        cout << space << bold() << "████████  ████████  ████████" << bold_end() << endl;
        cout << space << bold() << "████████  ████████  ████████" << bold_end() << endl;
        cout << space << bold() << "████████  ████████  ████████" << bold_end() << endl;
        cout << space << bold() << "████████  ████████  ████████" << bold_end() << endl;
        cout << space << bold() << "████████  ████████  ████████" << bold_end() << endl;
    }
    if (distribution_file() == "ArchLinux" || distribution_file() == "Arch Linux" || distribution_file() == "Arch")
    {
        int ter_width = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-ter-size.txt", 2).c_str() );
        string space;

        int count = (ter_width / 2) - (40 / 2);
        for (int i = 0; i < count; i++)
        {
            space += " ";
        }

        cout << space << bold() << "                  .o+`                 " << bold_end() << endl;
        cout << space << bold() << "                 `ooo/                 " << bold_end() << endl;
        cout << space << bold() << "                `+oooo:                " << bold_end() << endl;
        cout << space << bold() << "               `+oooooo:               " << bold_end() << endl;
        cout << space << bold() << "               -+oooooo+:              " << bold_end() << endl;
        cout << space << bold() << "             `/:-:++oooo+:             " << bold_end() << endl;
        cout << space << bold() << "            `/++++/+++++++:            " << bold_end() << endl;
        cout << space << bold() << "           `/++++++++++++++:           " << bold_end() << endl;
        cout << space << bold() << "          `/+++ooooooooooooo/`         " << bold_end() << endl;
        cout << space << bold() << "         ./$ooosssso++osssssso+`       " << bold_end() << endl;
        cout << space << bold() << "        .oossssso-````/ossssss+`       " << bold_end() << endl;
        cout << space << bold() << "       -osssssso.      :ssssssso.      " << bold_end() << endl;
        cout << space << bold() << "      :osssssss/        osssso+++.     " << bold_end() << endl;
        cout << space << bold() << "     /ossssssss/        +ssssooo/-     " << bold_end() << endl;
        cout << space << bold() << "   `/ossssso+/:-        -:/+osssso+-   " << bold_end() << endl;
        cout << space << bold() << "  `+sso+:-`                 `.-/+oso:  " << bold_end() << endl;
        cout << space << bold() << " `++:.                           `-/+/ " << bold_end() << endl;
        cout << space << bold() << " .`                                 `/ " << bold_end() << endl;
    }
    if (distribution_file() == "KaliLinux" || distribution_file() == "Kali Linux" || distribution_file() == "Kali")
    {
        int ter_width = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-ter-size.txt", 2).c_str() );
        string space;

        int count = (ter_width / 2) - (49 / 2);
        for (int i = 0; i < count; i++)
        {
            space += " ";
        }

        cout << space << bold() << "..............                                  " << bold_end() << endl;
        cout << space << bold() << "            ..,;:ccc,.                          " << bold_end() << endl;
        cout << space << bold() << "          ......''';lxO.                        " << bold_end() << endl;
        cout << space << bold() << ".....''''..........,:ld;                        " << bold_end() << endl;
        cout << space << bold() << "           .';;;:::;,,.x,                       " << bold_end() << endl;
        cout << space << bold() << "      ..'''.            0Xxoc:,.  ...           " << bold_end() << endl;
        cout << space << bold() << "  ....                ,ONkc;,;cokOdc',.         " << bold_end() << endl;
        cout << space << bold() << " .                   OMo           ':ddo.       " << bold_end() << endl;
        cout << space << bold() << "                    dMc               :OO;      " << bold_end() << endl;
        cout << space << bold() << "                    0M.                 .:o.    " << bold_end() << endl;
        cout << space << bold() << "                    ;Wd                         " << bold_end() << endl;
        cout << space << bold() << "                     ;XO,                       " << bold_end() << endl;
        cout << space << bold() << "                       ,d0Odlc;,..              " << bold_end() << endl;
        cout << space << bold() << "                           ..',;:cdOOd::,.      " << bold_end() << endl;
        cout << space << bold() << "                                    .:d;.':;.   " << bold_end() << endl;
        cout << space << bold() << "                                       'd,  .'  " << bold_end() << endl;
        cout << space << bold() << "                                         ;l   .." << bold_end() << endl;
        cout << space << bold() << "                                          .o    " << bold_end() << endl;
        cout << space << bold() << "                                            c   " << bold_end() << endl;
        cout << space << bold() << "                                            .'  " << bold_end() << endl;
        cout << space << bold() << "                                             .  " << bold_end() << endl;
    }
    if (distribution_file() == "Ubuntu")
    {
        int ter_width = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-ter-size.txt", 2).c_str() );
        string space;

        int count = (ter_width / 2) - (24 / 2);
        for (int i = 0; i < count; i++)
        {
            space += " ";
        }

        cout << space << bold() << "               .-.     " << bold_end() << endl;
        cout << space << bold() << "         .-'``(   )    " << bold_end() << endl;
        cout << space << bold() << "      ,`\\ \\    `-`.    " << bold_end() << endl;
        cout << space << bold() << "     /   \\ '``-.   `   " << bold_end() << endl;
        cout << space << bold() << "   .-.  ,       `___:  " << bold_end() << endl;
        cout << space << bold() << "  (   ) :        ___   " << bold_end() << endl;
        cout << space << bold() << "   `-`  `       ,   :  " << bold_end() << endl;
        cout << space << bold() << "     \\   / ,..-`   ,   " << bold_end() << endl;
        cout << space << bold() << "      `./ /    .-.`    " << bold_end() << endl;
        cout << space << bold() << "         `-..-(   )    " << bold_end() << endl;
        cout << space << bold() << "               `-`     " << bold_end() << endl;
    }
}