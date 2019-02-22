/*
 * functions_command.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include "functions_command.h"
#include "functions_file.h"

using namespace std;

void command_check_folder_exist() {
	string user = getenv("USER");
	char check;
	ifstream mem_file("/systeminfo-files"); //---------------/ systeminfo-files is a directory /---------------
	if(mem_file.good() == false) {
		cout << "Not found folder \"/systeminfo-files\"" << endl;
		cout << "Create folder /systeminfo-files? [y/n]... ";
		cin >> check;
		switch(check) {
		case 'y':
			cout << "------------------------------------------------------------------------" << endl;
			if (user == "root") {
				system("mkdir /systeminfo-files"); 					cout << "Creating \"systeminfo-files\" folder,.. done." << endl;
				system("mkdir /systeminfo-files/logs");				cout << "Creating \"logs\" folder,.............. done" << endl;
				system("chmod 777 /systeminfo-files");				cout << "Granting access /systeminfo-files,... done." << endl;
				system("chmod 777 /systeminfo-files/logs");			cout << "Granting access /logs,............... done." << endl;
			}
			else {
				system("sudo mkdir /systeminfo-files"); 			cout << "Creating \"systeminfo-files\" folder,.. done." << endl;
				system("sudo mkdir /systeminfo-files/logs");		cout << "Creating \"logs\" folder,.............. done" << endl;
				system("sudo chmod 777 /systeminfo-files");			cout << "Granting access /systeminfo-files,... done." << endl;
				system("sudo chmod 777 /systeminfo-files/logs");	cout << "Granting access /logs,............... done." << endl;
			}
			cout << "------------------------------------------------------------------------" << endl;
			break;
		case 'n':
			exit(0);
		default:
			exit(0);
		}
	}
}

void command_activate() {
	system("cd /systeminfo-files && uptime -p | awk '{for (i=2; i<NF; i++) printf $i \" \"; print $NF}' >> systeminfo-uptime.txt");
	system("cd /systeminfo-files && lsb_release -i | awk {'print $3'} >> systeminfo-distro.txt");
	system("cd /systeminfo-files && lsb_release -r | awk {'print $2'} >> systeminfo-distro.txt");
	system("cd /systeminfo-files && arch >> systeminfo-distro.txt");
	system("cd /systeminfo-files && getconf LONG_BIT >> systeminfo-distro.txt");
	system("cd /systeminfo-files && echo $USER >> systeminfo-user.txt");
	system("cd /systeminfo-files && echo $SHELL >> systeminfo-shell.txt");
	//Memory
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"MemTotal: \" --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-mem.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"MemFree: \" --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-mem.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"MemAvailable:\" --max-count=1 | awk {'print $2'} >> systeminfo-mem.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"SwapTotal: \" --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-swap.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"SwapFree: \" --max-count=1 | awk {'print $2'} | tr -d 'kB' >> systeminfo-swap.txt");
	//CPU
	system("cd /systeminfo-files && cat /proc/cpuinfo | grep -i \"model name\" --max-count=1 | awk '{for (i=4; i<NF; i++) printf $i \" \"; print $NF}' >> systeminfo-cpu.txt");
	system("cd /systeminfo-files && lscpu | grep -i \"CPU(s):\" --max-count=1 | awk {'print $2'}  >> systeminfo-cores.txt");
	system("cd /systeminfo-files && lscpu | grep -i \"max\" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency_max.txt");
	system("cd /systeminfo-files && lscpu | grep -i \"min\" --max-count=1 | awk {'print $4'} >> systeminfo-cpu-frequency_min.txt");
}

void command_remove() {
	system("cd /systeminfo-files && rm systeminfo-uptime.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-distro.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-shell.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-user.txt >> systeminfo-errors.txt");
	//Memory
	system("cd /systeminfo-files && rm systeminfo-mem.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-swap.txt >> systeminfo-errors.txt");
	//CPU
	system("cd /systeminfo-files && rm systeminfo-cpu.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-cores.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-cpu-frequency*.txt >> systeminfo-errors.txt");
}