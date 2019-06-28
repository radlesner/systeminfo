#include "function_output_logo.h"
#include "functions_strings_operations.h"
#include "functions_file_operations.h"
#include "functions_file.h"

using namespace std;

string logo_spaces(int n)
{
    int ter_width = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-ter-size.txt", 2).c_str() );
    string space;

    int count = (ter_width / 2) - (n / 2);
    for (int i = 0; i < count; i++)
    {
        space += " ";
    }

    return space;
}

void get_logo()
{
    if (distribution_file() == "ManjaroLinux" || distribution_file() == "Manjaro Linux" || distribution_file() == "Manjaro")
    {
        string space = logo_spaces(28);

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
    else if (distribution_file() == "ArchLinux" || distribution_file() == "Arch Linux" || distribution_file() == "Arch")
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
    else if (distribution_file() == "KaliLinux" || distribution_file() == "Kali Linux" || distribution_file() == "Kali")
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
    else if (distribution_file() == "Ubuntu")
    {
        int ter_width = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-ter-size.txt", 2).c_str() );
        string space;

        int count = (ter_width / 2) - (24 / 2);
        for (int i = 0; i < count; i++)
        {
            space += " ";
        }

        string shell;
        shell = getenv ("SHELL");

        struct utsname buffer;

        if (uname(&buffer) != 0)
        {
            perror("uname");
            exit(EXIT_FAILURE);
        }

        cout << space << bold() << "               .-.     " << bold_end() << endl;
        cout << space << bold() << "         .-'``(   )    " << bold_end() << endl;
        cout << space << bold() << "      ,`\\ \\    `-`.    " << bold_end() << endl;
        cout << space << bold() << "     /   \\ '``-.   `   " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << bold_end() << endl;
        cout << space << bold() << "   .-.  ,       `___:  " << buffer.release << bold_end() << endl;
        cout << space << bold() << "  (   ) :        ___   " << uptime_file() << bold_end() << endl;
        cout << space << bold() << "   `-`  `       ,   :  " << bold_end() << endl;
        cout << space << bold() << "     \\   / ,..-`   ,   " << bold_end() << endl;
        cout << space << bold() << "      `./ /    .-.`    " << bold_end() << endl;
        cout << space << bold() << "         `-..-(   )    " << bold_end() << endl;
        cout << space << bold() << "               `-`     " << bold_end() << endl;
    }
    else if (distribution_file() == "Raspbian GNU/Linux" || distribution_file() == "Raspbian")
    {
        int ter_width = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-ter-size.txt", 2).c_str() );
        string space;

        int count = (ter_width / 2) - (36 / 2);
        for (int i = 0; i < count; i++)
        {
            space += " ";
        }

        cout << space << bold() << "  `.::///+:/-.        --///+//-:`` " << bold_end() << endl;
        cout << space << bold() << " `+oooooooooooo:   `+oooooooooooo: " << bold_end() << endl;
        cout << space << bold() << "  /oooo++//ooooo:  ooooo+//+ooooo. " << bold_end() << endl;
        cout << space << bold() << "  `+ooooooo:-:oo-  +o+::/ooooooo:  " << bold_end() << endl;
        cout << space << bold() << "   `:oooooooo+``    `.oooooooo+-   " << bold_end() << endl;
        cout << space << bold() << "     `:++ooo/.        :+ooo+/.`    " << bold_end() << endl;
        cout << space << bold() << "        ${c2}...`  `.----.` ``..   " << bold_end() << endl;
        cout << space << bold() << "     .::::-``:::::::::.`-:::-`     " << bold_end() << endl;
        cout << space << bold() << "    -:::-`   .:::::::-`  `-:::-    " << bold_end() << endl;
        cout << space << bold() << "   `::.  `.--.`  `` `.---.``.::`   " << bold_end() << endl;
        cout << space << bold() << "       .::::::::`  -::::::::` `    " << bold_end() << endl;
        cout << space << bold() << " .::` .:::::::::- `::::::::::``::. " << bold_end() << endl;
        cout << space << bold() << "-:::` ::::::::::.  ::::::::::.`:::-" << bold_end() << endl;
        cout << space << bold() << "::::  -::::::::.   `-::::::::  ::::" << bold_end() << endl;
        cout << space << bold() << "-::-   .-:::-.``....``.-::-.   -::-" << bold_end() << endl;
        cout << space << bold() << " .. ``       .::::::::.     `..`.. " << bold_end() << endl;
        cout << space << bold() << "   -:::-`   -::::::::::`  .:::::`  " << bold_end() << endl;
        cout << space << bold() << "   :::::::` -::::::::::` :::::::.  " << bold_end() << endl;
        cout << space << bold() << "   .:::::::  -::::::::. ::::::::   " << bold_end() << endl;
        cout << space << bold() << "    `-:::::`   ..--.`   ::::::.    " << bold_end() << endl;
        cout << space << bold() << "      `...`  `...--..`  `...`      " << bold_end() << endl;
        cout << space << bold() << "            .::::::::::            " << bold_end() << endl;
        cout << space << bold() << "             `.-::::-`             " << bold_end() << endl;
    }
    else
    {
        cout << ">>> No logo for this distribution" << endl;
    }

}