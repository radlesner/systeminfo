/*
 * functions_command.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/utsname.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <cstring>

#include "functions_command.h"

using namespace std;

void command_activate() {
	system("cd /systeminfo-files && uptime -p | cut -d p -f2 >> systeminfo-uptime.txt");
	system("cd /systeminfo-files && lsb_release -i | cut -d\\: -f2 >> systeminfo-distro.txt");
	system("cd /systeminfo-files && cat /proc/cpuinfo | grep -i \"name\" --max-count=1 | cut -d\\: -f2 >> systeminfo-cpu.txt");
	system("cd /systeminfo-files && echo $SHELL >> systeminfo-shell.txt");
	system("cd /systeminfo-files && lscpu | grep -i \"CPU(s):\" --max-count=1 | cut -d\\: -f2 | tr -d ' '  >> systeminfo-cores.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"MemTotal: \" --max-count=1 | cut -d\\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-mem.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"MemAvailable: \" --max-count=1 | cut -d\\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-mem.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"SwapTotal: \" --max-count=1 | cut -d\\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-swap.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"SwapFree: \" --max-count=1 | cut -d\\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-swap.txt");
}
void command_remove() {
	system("cd /systeminfo-files && rm systeminfo-uptime.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-distro.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-cpu.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-cores.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-shell.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-mem.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-swap.txt >> systeminfo-errors.txt");
}
