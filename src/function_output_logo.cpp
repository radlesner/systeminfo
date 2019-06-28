#include "function_output_logo.h"
#include "functions_output.h"
#include "functions_strings_operations.h"
#include "functions_file_operations.h"
#include "functions_file.h"
#include "functions_file_memory.h"
#include "functions_file_swap.h"
#include "functions_network.h"

using namespace std;

void get_logo_output()
{
    if (distribution_file() == "ManjaroLinux" || distribution_file() == "Manjaro Linux" || distribution_file() == "Manjaro")
    {
        string shell;
        shell = getenv ("SHELL");

        struct utsname buffer;

        if (uname(&buffer) != 0)
        {
            perror("uname");
            exit(EXIT_FAILURE);
        }

        cout << bold() << "██████████████████  ████████  Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << bold() << "██████████████████  ████████  Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << bold() << "██████████████████  ████████  Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << bold() << "██████████████████  ████████  System architecture" << bold_end() << ": " << architecture() << endl;
        cout << bold() << "████████            ████████  Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << bold() << "████████  ████████  ████████  Shell" << bold_end() << ": " << architecture() << endl;
        cout << bold() << "████████  ████████  ████████  " << bold_end();
        mem_file(1);
        cout << bold() << "████████  ████████  ████████  " << bold_end();
        swap_file(1);
        cout << bold() << "████████  ████████  ████████  CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << bold() << "████████  ████████  ████████  Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << bold() << "████████  ████████  ████████  CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
        cout << bold() << "████████  ████████  ████████  Max Frequency" << bold_end() << ": " << cpu_freq_max() << " MHz" << endl;
        cout << bold() << "████████  ████████  ████████  Min Frequency" << bold_end() << ": " << cpu_freq_min() << " MHz" << endl;
        cout << bold() << "████████  ████████  ████████  Fan speed" << bold_end() << ": " << fan_speed() << endl;
    }
    else if (distribution_file() == "ArchLinux" || distribution_file() == "Arch Linux" || distribution_file() == "Arch")
    {
        string shell;
        shell = getenv ("SHELL");

        struct utsname buffer;

        if (uname(&buffer) != 0)
        {
            perror("uname");
            exit(EXIT_FAILURE);
        }

        cout << bold() << "                 .o+`                 Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << bold() << "                `ooo/                 Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << bold() << "               `+oooo:                Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << bold() << "              `+oooooo:               System architecture" << bold_end() << ": " << architecture() << endl;
        cout << bold() << "              -+oooooo+:              Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << bold() << "            `/:-:++oooo+:             Shell" << bold_end() << ": " << architecture() << endl;
        cout << bold() << "           `/++++/+++++++:            " << bold_end();
        mem_file(1);
        cout << bold() << "          `/++++++++++++++:           " << bold_end();
        swap_file(1);
        cout << bold() << "         `/+++ooooooooooooo/`         CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << bold() << "        ./$ooosssso++osssssso+`       Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << bold() << "       .oossssso-````/ossssss+`       CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
        cout << bold() << "      -osssssso.      :ssssssso.      Max Frequency" << bold_end() << ": " << cpu_freq_max() << " MHz" << endl;
        cout << bold() << "      :osssssss/        osssso+++.     Min Frequency" << bold_end() << ": " << cpu_freq_min() << " MHz" << endl;
        cout << bold() << "    /ossssssss/        +ssssooo/-     Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << bold() << "  `/ossssso+/:-        -:/+osssso+-   " << bold_end() << endl;
        cout << bold() << " `+sso+:-`                 `.-/+oso:  " << bold_end() << endl;
        cout << bold() << "`++:.                           `-/+/ " << bold_end() << endl;
        cout << bold() << ".`                                 `/ " << bold_end() << endl;
    }
    else if (distribution_file() == "KaliLinux" || distribution_file() == "Kali Linux" || distribution_file() == "Kali")
    {
        string shell;
        shell = getenv ("SHELL");

        struct utsname buffer;

        if (uname(&buffer) != 0)
        {
            perror("uname");
            exit(EXIT_FAILURE);
        }

        cout << bold() << "                  /                     Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << bold() << "              %.,&                      Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << bold() << "            (&.&%  %&,&&                Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << bold() << "          #&&&&&&&&&&&&&&&&(,           System architecture" << bold_end() << ": " << architecture() << endl;
        cout << bold() << "        %&&&&&&&&&&(//(%&&&&/,          Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << bold() << "      #&&&&&&&&           %&&&*.        Shell" << bold_end() << ": " << architecture() << endl;
        cout << bold() << "     &&(&&&&(              #&&&%***.    " << bold_end();
        mem_file(1);
        cout << bold() << "   ,&&&&&&&                #&&&*****,   " << bold_end();
        swap_file(1);
        cout << bold() << "   #&&&&.                 #&&&&/******. CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << bold() << ".&&&                  .&&&&%******,,.   Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << bold() << " (&&%                 %&&&%******,,,,,  Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << bold() << "    ,            .%&&&&*******,,,,,,,.  CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
        cout << bold() << "              #&&&%********,,,,,,,,,,   Max Frequency" << bold_end() << ": " << cpu_freq_max() << " MHz" << endl;
        cout << bold() << "           ,&&(**********,,,,,,,,,,,    Min Frequency" << bold_end() << ": " << cpu_freq_min() << " MHz" << endl;
        cout << bold() << "          &&**********,,,,,,,,,,,,,     " << bold_end() << endl;
        cout << bold() << "         (/********,,,,,,,,,,,,,,.      " << bold_end() << endl;
        cout << bold() << "         #******,,,,,,,,,,,,,,,.        " << bold_end() << endl;
        cout << bold() << "          ****,,,,,,,,,,,,,,,.          " << bold_end() << endl;
        cout << bold() << "            ,,,,,,,,,,,,,,              " << bold_end() << endl;
        cout << bold() << "             .,,,,,,,.                  " << bold_end() << endl;
    }
    else if (distribution_file() == "Ubuntu")
    {
        string shell;
        shell = getenv ("SHELL");

        struct utsname buffer;

        if (uname(&buffer) != 0)
        {
            perror("uname");
            exit(EXIT_FAILURE);
        }

        cout << bold() << "               .-.     " << bold_end() << endl;
        cout << bold() << "         .-'``(   )    " << bold_end() << endl;
        cout << bold() << "      ,`\\ \\    `-`.    " << bold_end() << endl;
        cout << bold() << "     /   \\ '``-.   `   " << bold_end() << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << bold() << "   .-.  ,       `___:  " << bold_end() << buffer.release << endl;
        cout << bold() << "  (   ) :        ___   " << bold_end() << uptime_file() << endl;
        cout << bold() << "   `-`  `       ,   :  " << bold_end() << cpu_file() << endl;
        cout << bold() << "     \\   / ,..-`   ,   " << bold_end() << cpu_frequency() << endl;
        cout << bold() << "      `./ /    .-.`    " << bold_end() << endl;
        cout << bold() << "         `-..-(   )    " << bold_end() << endl;
        cout << bold() << "               `-`     " << bold_end() << endl;
    }
    else if (distribution_file() == "Raspbian GNU/Linux" || distribution_file() == "Raspbian")
    {
        string shell;
        shell = getenv ("SHELL");

        struct utsname buffer;

        if (uname(&buffer) != 0)
        {
            perror("uname");
            exit(EXIT_FAILURE);
        }

        cout << get_color("green") << "  `.::///+:/-.        --///+//-:``  " << get_color("reset") << bold() << "Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << get_color("green") << " `+oooooooooooo:   `+oooooooooooo:  " << get_color("reset") << bold() << "Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << get_color("green") << "  /oooo++//ooooo:  ooooo+//+ooooo.  " << get_color("reset") << bold() << "Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << get_color("green") << "  `+ooooooo:-:oo-  +o+::/ooooooo:   " << get_color("reset") << bold() << "System architecture" << bold_end() << ": " << architecture() << endl;
        cout << get_color("green") << "   `:oooooooo+``    `.oooooooo+-    " << get_color("reset") << bold() << "Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << get_color("green") << "     `:++ooo/.        :+ooo+/.`     " << get_color("reset") << bold() << "Shell" << bold_end() << ": " << architecture() << endl;
        cout << get_color("green") << "        ...`  `.----.` ``..         " << get_color("reset");
        mem_file(1);
        cout << bold() << "     .::::-``:::::::::.`-:::-`      " << bold_end();
        swap_file(1);
        cout << bold() << "    -:::-`   .:::::::-`  `-:::-     CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << bold() << "   `::.  `.--.`  `` `.---.``.::`    Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << bold() << "       .::::::::`  -::::::::` `     CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
        cout << bold() << " .::` .:::::::::- `::::::::::``::.  Max Frequency" << bold_end() << ": " << cpu_freq_max() << " MHz" << endl;
        cout << bold() << "-:::` ::::::::::.  ::::::::::.`:::- Min Frequency" << bold_end() << ": " << cpu_freq_min() << " MHz" << endl;
        cout << bold() << "::::  -::::::::.   `-::::::::  :::: Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << bold() << "-::-   .-:::-.``....``.-::-.   -::- " << bold_end() << endl;
        cout << bold() << " .. ``       .::::::::.     `..`..  " << bold_end() << endl;
        cout << bold() << "   -:::-`   -::::::::::`  .:::::`   " << bold_end() << endl;
        cout << bold() << "   :::::::` -::::::::::` :::::::.   " << bold_end() << endl;
        cout << bold() << "   .:::::::  -::::::::. ::::::::    " << bold_end() << endl;
        cout << bold() << "    `-:::::`   ..--.`   ::::::.     " << bold_end() << endl;
        cout << bold() << "      `...`  `...--..`  `...`       " << bold_end() << endl;
        cout << bold() << "            .::::::::::             " << bold_end() << endl;
        cout << bold() << "             `.-::::-`              " << bold_end() << endl;
    }
    else if (distribution_file() == "Debian GNU/Linux" || distribution_file() == "Debian")
    {
        string shell;
        shell = getenv ("SHELL");

        struct utsname buffer;

        if (uname(&buffer) != 0)
        {
            perror("uname");
            exit(EXIT_FAILURE);
        }

        cout << bold() << "       _,met$$$$$gg.        Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << bold() << "    ,g$$$$$$$$$$$$$$$P.     Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << bold() << "  ,g$$P\"     \"\"\"Y$$.\".      Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << bold() << " ,$$P'              `$$$.   System architecture" << bold_end() << ": " << architecture() << endl;
        cout << bold() << "',$$P       ,ggs.     `$$b: Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << bold() << "`d$$'     ,$P\"'   .    $$$  Shell" << bold_end() << ": " << architecture() << endl;
        cout << bold() << " $$P      d$'     ,    $$P  " << bold_end();
        mem_file(1);
        cout << bold() << " $$:      $$.   -    ,d$$'  " << bold_end();
        swap_file(1);
        cout << bold() << " $$;      Y$b._   _,d$P'    CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << bold() << " Y$$.    `.`\"Y$$$$P\"'       Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << bold() << " `$$b      \"-.__            CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
        cout << bold() << "  `Y$$                      Max Frequency" << bold_end() << ": " << cpu_freq_max() << " MHz" << endl;
        cout << bold() << "   `Y$$.                    Min Frequency" << bold_end() << ": " << cpu_freq_min() << " MHz" << endl;
        cout << bold() << "     `$$b.                  Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << bold() << "       `Y$$b.               " << bold_end() << endl;
        cout << bold() << "          `\"Y$b._           " << bold_end() << endl;
        cout << bold() << "              `\"\"\"          " << bold_end() << endl;
    }
    else
    {
        cout << ">>> No logo for this distribution" << endl;
    }

}