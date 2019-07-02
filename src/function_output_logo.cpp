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
    string logo_output[32];
    string shell;
    shell = getenv ("SHELL");

    struct utsname buffer;

    if (uname(&buffer) != 0)
    {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    if (distribution_file() == "ManjaroLinux" || distribution_file() == "Manjaro Linux" || distribution_file() == "Manjaro")
    {
        logo_output[0]  = "██████████████████  ████████";
        logo_output[1]  = "██████████████████  ████████";
        logo_output[2]  = "██████████████████  ████████";
        logo_output[3]  = "██████████████████  ████████";
        logo_output[4]  = "████████            ████████";
        logo_output[5]  = "████████  ████████  ████████";
        logo_output[6]  = "████████  ████████  ████████";
        logo_output[7]  = "████████  ████████  ████████";
        logo_output[8]  = "████████  ████████  ████████";
        logo_output[9]  = "████████  ████████  ████████";
        logo_output[10] = "████████  ████████  ████████";
        logo_output[11] = "████████  ████████  ████████";
        logo_output[12] = "████████  ████████  ████████";
        logo_output[13] = "████████  ████████  ████████";


        cout << bold() << logo_output[0] << "  Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << bold() << logo_output[1] << "  Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << bold() << logo_output[2] << "  Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << bold() << logo_output[3] << "  System architecture" << bold_end() << ": " << architecture() << endl;
        cout << bold() << logo_output[4] << "  Shell" << bold_end() << ": " << architecture() << endl;
        cout << bold() << logo_output[5] << "  Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << bold() << logo_output[6] << "  " << bold_end();
        mem_file(1);
        cout << bold() << logo_output[7] << "  " << bold_end();
        swap_file(1);
        cout << bold() << logo_output[8] << "  CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << bold() << logo_output[9] << "  Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << bold() << logo_output[10] << "  CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
        cout << bold() << logo_output[11] << "  Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << bold() << logo_output[12] << "  " << bold_end() << endl;
        cout << bold() << logo_output[13] << "  " << bold_end() << endl;
    }
    else if (distribution_file() == "ArchLinux" || distribution_file() == "Arch Linux" || distribution_file() == "Arch")
    {
        logo_output[0]  = "                 .o+`                 ";
        logo_output[1]  = "                `ooo/                 ";
        logo_output[2]  = "               `+oooo:                ";
        logo_output[3]  = "              `+oooooo:               ";
        logo_output[4]  = "              -+oooooo+:              ";
        logo_output[5]  = "            `/:-:++oooo+:             ";
        logo_output[6]  = "           `/++++/+++++++:            ";
        logo_output[7]  = "          `/++++++++++++++:           ";
        logo_output[8]  = "         `/+++ooooooooooooo/`         ";
        logo_output[9]  = "        ./ooosssso++osssssso+`        ";
        logo_output[10] = "       .oossssso-````/ossssss+`       ";
        logo_output[11] = "      -osssssso.      :ssssssso.      ";
        logo_output[12] = "      :osssssss/       osssso+++.     ";
        logo_output[13] = "    /ossssssss/        +ssssooo/-     ";
        logo_output[14] = "  `/ossssso+/:-        -:/+osssso+-   ";
        logo_output[15] = " `+sso+:-`                 `.-/+oso:  ";
        logo_output[16] = "`++:.                           `-/+/ ";
        logo_output[17] = ".`                                 `/ ";

        cout << bold() << logo_output[0] << "Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << bold() << logo_output[1] << "Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << bold() << logo_output[2] << "Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << bold() << logo_output[3] << "System architecture" << bold_end() << ": " << architecture() << endl;
        cout << bold() << logo_output[4] << "Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << bold() << logo_output[5] << "Shell" << bold_end() << ": " << architecture() << endl;
        cout << bold() << logo_output[6] << "" << bold_end();
        mem_file(1);
        cout << bold() << logo_output[7] << "" << bold_end();
        swap_file(1);
        cout << bold() << logo_output[8] << "CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << bold() << logo_output[9] << "Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << bold() << logo_output[10] << "CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
        cout << bold() << logo_output[11] << "Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << bold() << logo_output[12] << "" << bold_end() << endl;
        cout << bold() << logo_output[13] << "" << bold_end() << endl;
        cout << bold() << logo_output[14] << "" << bold_end() << endl;
        cout << bold() << logo_output[15] << "" << bold_end() << endl;
        cout << bold() << logo_output[16] << "" << bold_end() << endl;
        cout << bold() << logo_output[17] << "" << bold_end() << endl;
    }
    else if (distribution_file() == "KaliLinux" || distribution_file() == "Kali Linux" || distribution_file() == "Kali")
    {
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
        cout << bold() << "              #&&&%********,,,,,,,,,,   Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << bold() << "           ,&&(**********,,,,,,,,,,,    " << bold_end() << endl;
        cout << bold() << "          &&**********,,,,,,,,,,,,,     " << bold_end() << endl;
        cout << bold() << "         (/********,,,,,,,,,,,,,,.      " << bold_end() << endl;
        cout << bold() << "         #******,,,,,,,,,,,,,,,.        " << bold_end() << endl;
        cout << bold() << "          ****,,,,,,,,,,,,,,,.          " << bold_end() << endl;
        cout << bold() << "            ,,,,,,,,,,,,,,              " << bold_end() << endl;
        cout << bold() << "             .,,,,,,,.                  " << bold_end() << endl;
    }
    else if (distribution_file() == "Ubuntu")
    {
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
        cout << bold() << " .::` .:::::::::- `::::::::::``::.  Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << bold() << "-:::` ::::::::::.  ::::::::::.`:::- " << bold_end() << endl;
        cout << bold() << "::::  -::::::::.   `-::::::::  :::: " << bold_end() << endl;
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
        cout << bold() << "  `Y$$                      Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << bold() << "   `Y$$.                    " << bold_end() << endl;
        cout << bold() << "     `$$b.                  " << bold_end() << endl;
        cout << bold() << "       `Y$$b.               " << bold_end() << endl;
        cout << bold() << "          `\"Y$b._           " << bold_end() << endl;
        cout << bold() << "              `\"\"\"          " << bold_end() << endl;
    }
    else if (distribution_file() == "Gentoo" || distribution_file() == "Gentoo/Linux")
    {
        logo_output[0] = get_color("purple") + "         -/oyddmdhs+:.              ";
        logo_output[1] = get_color("purple") + "     -o" + get_color("white") + "dNMMMMMMMMNNmhy+" + get_color("purple") + "-`           ";
        logo_output[2] = get_color("purple") + "   -y" + get_color("white") + "NMMMMMMMMMMMNNNmmdhy" + get_color("purple") + "+-         ";
        logo_output[3] = get_color("purple") + " `o" + get_color("white") + "mMMMMMMMMMMMMNmdmmmmddhhy" + get_color("purple") + "/`      ";
        logo_output[4] = get_color("purple") + " om" + get_color("white") + "MMMMMMMMMMMN" + get_color("purple") + "hhyyyo" + get_color("white") + "hmdddhhhd" + get_color("purple") + "o`    ";
        logo_output[5] = get_color("purple") + ".y" + get_color("white") + "dMMMMMMMMMMd" + get_color("purple") + "hs++so/s" + get_color("white") + "mdddhhhhdm" + get_color("purple") + "+`  ";
        logo_output[6] = get_color("purple") + " oy" + get_color("white") + "hdmNMMMMMMMN" + get_color("purple") + "dyooy" + get_color("white") + "dmddddhhhhyhN" + get_color("purple") + "d. " + get_color("reset");
        logo_output[7] = get_color("purple") + "  :o" + get_color("white") + "yhhdNNMMMMMMMNNNmmdddhhhhhyym" + get_color("purple") + "Mh " + get_color("reset");
        logo_output[8] = get_color("purple") + "    .:" + get_color("white") + "+sydNMMMMMNNNmmmdddhhhhhhmM" + get_color("purple") + "my ";
        logo_output[9] = get_color("purple") + "       /m" + get_color("white") + "MMMMMMNNNmmmdddhhhhhmMNh" + get_color("purple") + "s: ";
        logo_output[10] = get_color("purple") + "    `o" + get_color("white") + "NMMMMMMMNNNmmmddddhhdmMNhs" + get_color("purple") + "+`  ";
        logo_output[11] = get_color("purple") + "  `s" + get_color("white") + "NMMMMMMMMNNNmmmdddddmNMmhs" + get_color("purple") + "/.    ";
        logo_output[12] = get_color("purple") + " /N" + get_color("white") + "MMMMMMMMNNNNmmmdddmNMNdso" + get_color("purple") + ":`";
        logo_output[13] = get_color("purple") + "+M" + get_color("white") + "MMMMMMNNNNNmmmmdmNMNdso" + get_color("purple") + "/-";
        logo_output[14] = get_color("purple") + "yM" + get_color("white") + "MNNNNNNNmmmmmNNMmhs+/" + get_color("purple") + "-`";
        logo_output[15] = get_color("purple") + "/h" + get_color("white") + "MMNNNNNNNNMNdhs++/" + get_color("purple") + "-`";
        logo_output[16] = get_color("purple") + "`/" + get_color("white") + "ohdmmddhys+++/:" + get_color("purple") + ".`";
        logo_output[17] = get_color("purple") + "  `-//////:--.";

        cout << logo_output[0] << get_color("purple") << "Model name" << get_color("reset") << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << logo_output[1] << get_color("purple") << "Distribution" << get_color("reset") << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << logo_output[2] << get_color("purple") << "Kernel version" << get_color("reset") << ": " << buffer.release << endl;
        cout << logo_output[3] << get_color("purple") << "System architecture" << get_color("reset") << ": " << architecture() << endl;
        cout << logo_output[4] << get_color("purple") << "Uptime" << get_color("reset") << ": " << uptime_file() << endl;
        cout << logo_output[5] << get_color("purple") << "Shell" << get_color("reset") << ": " << architecture() << endl;
        cout << logo_output[6] << get_color("purple") << get_color("reset");
        mem_file(1);
        cout << logo_output[7] << get_color("purple") << get_color("reset");
        swap_file(1);
        cout << logo_output[8] << get_color("purple") << "CPU" << get_color("reset") << ": " << cpu_file() << endl;
        cout << logo_output[9] << get_color("purple") << "Cores/theards" << get_color("reset") << ": " << cores_file() << "/" << theards_file() << endl;
        cout << logo_output[10] << get_color("purple") << "CPU Frequency" << get_color("reset") << ": " << cpu_frequency() << " MHz" << endl;
        cout << logo_output[11] << get_color("purple") << "Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << logo_output[12] << get_color("purple") << "" << endl;
        cout << logo_output[13] << get_color("purple") << "" << endl;
        cout << logo_output[14] << get_color("purple") << "" << endl;
        cout << logo_output[15] << get_color("purple") << "" << endl;
        cout << logo_output[16] << get_color("purple") << "" << endl;
        cout << logo_output[17] << get_color("purple") << "" << endl;
    }
    else if (distribution_file() == "Fedora")
    {
        logo_output[0] = get_color("blue") + "          /:-------------:\\        ";
        logo_output[1] = get_color("blue") + "       :-------------------::      ";
        logo_output[2] = get_color("blue") + "     :-----------" + get_color("white") + "/shhOHbmp" + get_color("blue") + "---:\\    ";
        logo_output[3] = get_color("blue") + "   /-----------" + get_color("white") + "omMMMNNNMMD  " + get_color("blue") + "---:   ";
        logo_output[4] = get_color("blue") + "  :-----------" + get_color("white") + "sMMMMNMNMP" + get_color("blue") + ".    ---:  ";
        logo_output[5] = get_color("blue") + " :-----------" + get_color("white") + ":MMMdP" + get_color("blue") + "-------    ---\\ ";
        logo_output[6] = get_color("blue") + ",------------" + get_color("white") + ":MMMd" + get_color("blue") + "--------    ---: ";
        logo_output[7] = get_color("blue") + ":------------" + get_color("white") + ":MMMd" + get_color("blue") + "-------    .---: ";
        logo_output[8] = get_color("blue") + ":----    " + get_color("white") + "oNMMMMMMMMMNho" + get_color("blue") + "     .----: ";
        logo_output[9] = get_color("blue") + ":--     ." + get_color("white") + "+shhhMMMmhhy++" + get_color("blue") + "   .------/ ";
        logo_output[10] = get_color("blue") + ":-    -------" + get_color("white") + ":MMMd" + get_color("blue") + "--------------:  ";
        logo_output[11] = get_color("blue") + ":-   --------" + get_color("white") + "/MMMd" + get_color("blue") + "-------------;   ";
        logo_output[12] = get_color("blue") + ":-    ------" + get_color("white") + "/hMMMy" + get_color("blue") + "------------:    ";
        logo_output[13] = get_color("blue") + ":--" + get_color("white") + " :dMNdhhdNMMNo" + get_color("blue") + "------------;     ";
        logo_output[13] = get_color("blue") + ":---" + get_color("white") + ":sdNMMMMNds:" + get_color("blue") + "------------:      ";
        logo_output[14] = get_color("blue") + ":------" + get_color("white") + ":://:" + get_color("blue") + "-------------::        ";
        logo_output[15] = get_color("blue") + ":---------------------://                    " + get_color("reset");


        cout << get_color("blue") << logo_output[1] << "Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << get_color("blue") << logo_output[2] << "Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << get_color("blue") << logo_output[3] << "Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << get_color("blue") << logo_output[4] << "System architecture" << bold_end() << ": " << architecture() << endl;
        cout << get_color("blue") << logo_output[5] << "Shell" << bold_end() << ": " << architecture() << endl;
        cout << get_color("blue") << logo_output[6] << "Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << get_color("blue") << logo_output[7] << "" << bold_end();
        mem_file(1);
        cout << get_color("blue") << logo_output[8] << "" << bold_end();
        swap_file(1);
        cout << get_color("blue") << logo_output[9] << "CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << get_color("blue") << logo_output[10] << "Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << get_color("blue") << logo_output[11] << "CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
        cout << get_color("blue") << logo_output[12] << "Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << get_color("blue") << logo_output[13] << get_color("reset") << endl;
        cout << get_color("blue") << logo_output[14] << get_color("reset") << endl;
        cout << get_color("blue") << logo_output[15] << get_color("reset") << endl;
        cout << get_color("blue") << logo_output[16] << get_color("reset") << endl;
        cout << get_color("blue") << logo_output[17] << get_color("reset") << endl;
    }
    else if (distribution_file() == "Android")
    {

        logo_output[0]  = "     ╲ ▁▂▂▂▁ ╱      ";
        logo_output[1]  = "     ▄███████▄      ";
        logo_output[2]  = "    ▄██ ███ ██▄     ";
        logo_output[3]  = "   ▄███████████▄    ";
        logo_output[4]  = "▄█ ▄▄▄▄▄▄▄▄▄▄▄▄▄ █▄ ";
        logo_output[5]  = "██ █████████████ ██ ";
        logo_output[6]  = "██ █████████████ ██ ";
        logo_output[7]  = "██ █████████████ ██ ";
        logo_output[8]  = "██ █████████████ ██ ";
        logo_output[9]  = "   █████████████    ";
        logo_output[10] = "    ███████████     ";
        logo_output[11] = "     ██     ██      ";
        logo_output[12] = "     ██     ██      ";

        cout << bold() << logo_output[0] << "Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << bold() << logo_output[1] << "Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << bold() << logo_output[2] << "Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << bold() << logo_output[3] << "System architecture" << bold_end() << ": " << architecture() << endl;
        cout << bold() << logo_output[4] << "Shell" << bold_end() << ": " << architecture() << endl;
        cout << bold() << logo_output[5] << "Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << bold() << logo_output[6];
        mem_file(1);
        cout << bold() << logo_output[7];
        swap_file(1);
        cout << bold() << logo_output[8] << "CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << bold() << logo_output[9] << "Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << bold() << logo_output[10] << "CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
        cout << bold() << logo_output[11] << "Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << bold() << logo_output[12] << endl;
    }
    else if (distribution_file() == "elementary" || distribution_file() == "Elementary")
    {
        cout << get_color("white") << "         eeeeeeeeeeeeeeeee          " << bold() << "Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << get_color("white") << "      eeeeeeeeeeeeeeeeeeeeeee       " << bold() << "Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << get_color("white") << "    eeeee  eeeeeeeeeeee   eeeee     " << bold() << "Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << get_color("white") << "  eeee   eeeee       eee     eeee   " << bold() << "System architecture" << bold_end() << ": " << architecture() << endl;
        cout << get_color("white") << " eeee   eeee          eee     eeee  " << bold() << "Shell" << bold_end() << ": " << architecture() << endl;
        cout << get_color("white") << "eee    eee            eee       eee " << bold() << "Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << get_color("white") << "eee   eee            eee        eee " << get_color("reset");
        mem_file(1);
        cout << get_color("white") << "ee    eee           eeee       eeee " << get_color("reset");
        swap_file(1);
        cout << get_color("white") << "ee    eee         eeeee      eeeeee " << bold() << "CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << get_color("white") << "ee    eee       eeeee      eeeee ee " << bold() << "Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << get_color("white") << "eee   eeee   eeeeee      eeeee  eee " << bold() << "CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
        cout << get_color("white") << "eee    eeeeeeeeee     eeeeee    eee " << bold() << "Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << get_color("white") << " eeeeeeeeeeeeeeeeeeeeeeee    eeeee  " << get_color("reset") << endl;
        cout << get_color("white") << "  eeeeeeee eeeeeeeeeeee      eeee   " << get_color("reset") << endl;
        cout << get_color("white") << "    eeeee                 eeeee     " << get_color("reset") << endl;
        cout << get_color("white") << "      eeeeeee         eeeeeee       " << get_color("reset") << endl;
        cout << get_color("white") << "         eeeeeeeeeeeeeeeee          " << get_color("reset") << endl;
    }
    else if (distribution_file() == "Linux" || distribution_file() == "linux")
    {
        logo_output[0] = get_color("dark_grey") + "        #####          ";
        logo_output[1] = get_color("dark_grey") + "       #######         ";
        logo_output[2] = get_color("dark_grey") + "       ##" + get_color("white") + "O" + get_color("dark_grey") + "#" + get_color("white") + "O" + get_color("dark_grey") + "##         ";
        logo_output[3] = get_color("dark_grey") + "       #" + get_color("yellow") + "#####" + get_color("dark_grey") + "#         ";
        logo_output[4] = get_color("dark_grey") + "     ##" + get_color("white") + "##" + get_color("yellow") + "###" + get_color("white") + "##" + get_color("dark_grey") + "##       ";
        logo_output[5] = get_color("dark_grey") + "    #" + get_color("white") + "##########" + get_color("dark_grey") + "##      ";
        logo_output[6] = get_color("dark_grey") + "   #" + get_color("white") + "############" + get_color("dark_grey") + "##     ";
        logo_output[7] = get_color("dark_grey") + "   #" + get_color("white") + "############" + get_color("dark_grey") + "###    ";
        logo_output[8] = get_color("yellow") + "  ##" + get_color("dark_grey") + "#" + get_color("white") + "###########" + get_color("dark_grey") + "##" + get_color("yellow") + "#    ";
        logo_output[9] = get_color("yellow") + "######" + get_color("dark_grey") + "#" + get_color("white") + "#######" + get_color("dark_grey") + "#" + get_color("yellow") + "######  ";
        logo_output[10] = get_color("yellow") + "#######" + get_color("dark_grey") + "#" + get_color("white") + "#####" + get_color("dark_grey") + "#" + get_color("yellow") + "#######  ";
        logo_output[11] = get_color("yellow") + "  #####" + get_color("dark_grey") + "#######" + get_color("yellow") + "#####";

        cout << logo_output[0]  << bold() << "Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << logo_output[1]  << bold() << "Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << logo_output[2]  << bold() << "Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << logo_output[3]  << bold() << "System architecture" << bold_end() << ": " << architecture() << endl;
        cout << logo_output[4]  << bold() << "Shell" << bold_end() << ": " << architecture() << endl;
        cout << logo_output[5]  << bold() << "Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << logo_output[6]  << get_color("reset");
        mem_file(1);
        cout << logo_output[7]  << get_color("reset");
        swap_file(1);
        cout << logo_output[8]  << bold() << "CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << logo_output[9]  << bold() << "Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << logo_output[10] << bold() << "Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << logo_output[11] << get_color("reset") << endl;
    }
    else
    {
        logo_output[0] = get_color("dark_grey") + "        #####          ";
        logo_output[1] = get_color("dark_grey") + "       #######         ";
        logo_output[2] = get_color("dark_grey") + "       ##" + get_color("white") + "O" + get_color("dark_grey") + "#" + get_color("white") + "O" + get_color("dark_grey") + "##         ";
        logo_output[3] = get_color("dark_grey") + "       #" + get_color("yellow") + "#####" + get_color("dark_grey") + "#         ";
        logo_output[4] = get_color("dark_grey") + "     ##" + get_color("white") + "##" + get_color("yellow") + "###" + get_color("white") + "##" + get_color("dark_grey") + "##       ";
        logo_output[5] = get_color("dark_grey") + "    #" + get_color("white") + "##########" + get_color("dark_grey") + "##      ";
        logo_output[6] = get_color("dark_grey") + "   #" + get_color("white") + "############" + get_color("dark_grey") + "##     ";
        logo_output[7] = get_color("dark_grey") + "   #" + get_color("white") + "############" + get_color("dark_grey") + "###    ";
        logo_output[8] = get_color("yellow") + "  ##" + get_color("dark_grey") + "#" + get_color("white") + "###########" + get_color("dark_grey") + "##" + get_color("yellow") + "#    ";
        logo_output[9] = get_color("yellow") + "######" + get_color("dark_grey") + "#" + get_color("white") + "#######" + get_color("dark_grey") + "#" + get_color("yellow") + "######  ";
        logo_output[10] = get_color("yessllow") + "#######" + get_color("dark_grey") + "#" + get_color("white") + "#####" + get_color("dark_grey") + "#" + get_color("yellow") + "#######  ";
        logo_output[11] = get_color("yellow") + "  #####" + get_color("dark_grey") + "#######" + get_color("yellow") + "#####";

        cout << logo_output[0]  << bold() << "Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
        cout << logo_output[1]  << bold() << "Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
        cout << logo_output[2]  << bold() << "Kernel version" << bold_end() << ": " << buffer.release << endl;
        cout << logo_output[3]  << bold() << "System architecture" << bold_end() << ": " << architecture() << endl;
        cout << logo_output[4]  << bold() << "Shell" << bold_end() << ": " << architecture() << endl;
        cout << logo_output[5]  << bold() << "Uptime" << bold_end() << ": " << uptime_file() << endl;
        cout << logo_output[6]  << get_color("reset");
        mem_file(1);
        cout << logo_output[7]  << get_color("reset");
        swap_file(1);
        cout << logo_output[8]  << bold() << "CPU" << bold_end() << ": " << cpu_file() << endl;
        cout << logo_output[9]  << bold() << "Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
        cout << logo_output[10] << bold() << "Fan speed" << bold_end() << ": " << fan_speed() << endl;
        cout << logo_output[11] << get_color("reset") << endl;
        cout << bold() << " No dedicated logo for" << bold_end() << endl;
        cout << bold() << "   this distribution  " << bold_end() << endl;
    }

}