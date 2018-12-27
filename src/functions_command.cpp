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
	ifstream mem_file("/systeminfo-files"); //------------------------/ systeminfo-files is a directory /------------------------
	if(mem_file.good() == false) {
		cout << "Not found \"/systeminfo-files\"" << endl;
		cout << "Create this folder /systeminfo-files? [y/n]... ";
		cin >> check;
		switch(check) {
		case 'y':
			cout << "------------------------------------------------------------------------" << endl;
			if (user == "root") {
				system("mkdir /systeminfo-files"); 			cout << "mkdir /systeminfo-files,.............. done." << endl;
				system("chmod 777 /systeminfo-files");		cout << "chmod 777 /systeminfo-files,.......... done." << endl;
			}
			else {
				system("sudo mkdir /systeminfo-files"); 	cout << "sudo mkdir /systeminfo-files,.........	done." << endl;
				system("sudo chmod 777 /systeminfo-files");	cout << "sudo chmod 777 /systeminfo-files,.....	done." << endl;
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
	system("cd /usr/bin && ./systeminfo-command-activate.sh");
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
