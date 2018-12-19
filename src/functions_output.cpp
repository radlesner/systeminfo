/*
 * functions_output.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include "functions_output.h"
#include "functions_output_memory_swap.h"
#include "functions_file.h"
#include "functions_file_memory.h"
#include "functions_file_swap.h"
#include "functions_command.h"

using namespace std;

void output_all() {
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "OS Name:			" << buffer.sysname << endl;
	cout << "Distribution:		" << distribution_file() << endl;
	cout << "Kernel version:			" << buffer.release << endl;
	cout << "System architecture:		" << buffer.machine << endl;
	cpu_file();
	cores_file();
	output_memory();
	shell_file();
	cout << "Logged user:			" << user_file() << endl;
	cout << "Hostname:			" << buffer.nodename << endl;
	cout << "Uptime:			       " << uptime_file() << endl;
}

void output_system() {
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "OS Name:			" << buffer.sysname << endl;
	cout << "Distribution:		" << distribution_file() << endl;
	cout << "Kernel version:			" << buffer.release << endl;
	cout << "System architecture:		" << buffer.machine << endl;
	cpu_file();
	cores_file();
	cout << "CPU Frequency:			" << cpu_frequency() << " MHz" << endl;
	shell_file();
}

void output_memory() {
	cout.precision(3);
	mem_file();
	swap_file();
}

void output_ssh_info() {
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "Hostname:			" << buffer.nodename << endl;
	cout << "Logged user:			" << user_file() << endl << endl;

	cout << "SSH Command:			" << user_file() << "@" << buffer.nodename << ".local" << endl;
}

void output_cpu_only() {
	cpu_file();
	cores_file();
}

void output_check_files() {
	ifstream mem_file("/systeminfo-files");							// systeminfo-files is a directory
	if(mem_file.good() == false) {
		command_check_folder_exist();
	}
	else {
		cout << "All files is integrated ✔" << endl;
	}
}

void output_monitor(int value_1, char** value_2) {
	for(;;) {
		system("clear");
		command_activate();

		if(value_1 > 2) {
			if(value_1 > 3)
				if(!strcmp(value_2[3], "-l") || !strcmp(value_2[3], "--logo"))	output_logo();
			if(!strcmp(value_2[2], "-m")) {
				cpu_file();
				cores_file();
				cout << "CPU Frequency:			" << cpu_frequency() << " MHz" << endl << endl;
				output_memory();
			}
			else if(!strcmp(value_2[2], "-M")){
				cpu_file();
				cores_file();
				cout << "CPU Frequency:			" << cpu_frequency() << " MHz" << endl << endl;
				output_memory_megabyte();
			}
			else {
				cout << "systeminfo: Too few arguments" << endl;
				break;
			}
		}
		else {
			cout << "systeminfo: Too few arguments" << endl;
			break;
		}

		command_remove();
		cout << endl << "Exit to: CTRL + C" << endl;
		sleep(1);
	}
}

void output_help() {
	cout << "Usage: system [optional_option]" << endl;
	cout << "Options:" << endl;
	cout << "	-m	--memory		RAM and Swap information in gigabyte form" << endl;
	cout << "	-M	--memory-megabyte	RAM and Swap information in megabyte form" << endl;
	cout << "	-s	--system		System and hardware information" << endl;
	cout << "	-h	--ssh			SSH information" << endl;
	cout << "	-c	--cpu			CPU information" << endl;
	cout << "	-l	--logo			Show the logo" << endl;
	cout << "		--check-files		Check integration files" << endl;
	cout << "		--help			Help panel" << endl;
	cout << "		--version		Version program and compilation" << endl;
	cout << "					information" << endl;
	cout << "Example: systeminfo -s -l" << endl;
}

void output_logo() {
   cout << " ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ " << endl;
   cout << "||S |||Y |||S |||T |||E |||M |||I |||N |||F |||O ||" << endl;
   cout << "||__|||__|||__|||__|||__|||__|||__|||__|||__|||__||" << endl;
   cout << "|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|" << endl;

   cout << endl;
}
