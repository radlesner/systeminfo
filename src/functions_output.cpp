/*
 * functions_output.cpp
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

#include "functions_output.h"
#include "functions_file.h"
#include "functions_file_memory.h"
#include "functions_file_swap.h"

using namespace std;

void output_all() {

	char* shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "OS Name:			" << buffer.sysname << endl;
	distribution_file();
	cout << "Kernel version:			" << buffer.release << endl;
	cout << "System architecture:		" << buffer.machine << endl;
	cpu_file();
	cores_file();
	cout.precision(3);
	mem_file();
	swap_file();
	shell_file();
	cout << "Hostname:			" << buffer.nodename << endl;
	uptime_file();
}

void output_system() {
	char* shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "OS Name:			" << buffer.sysname << endl;
	distribution_file();
	cout << "Kernel version:			" << buffer.release << endl;
	cout << "System architecture:		" << buffer.machine << endl;
	cpu_file();
	cores_file();
	shell_file();
}

void output_memory() {
	cout.precision(3);
	mem_file();
	swap_file();
}

void output_hostname_only() {
	char* shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "Hostname:			" << buffer.nodename << endl;
}

void output_cpu_only() {
	cpu_file();
	cores_file();
}

void output_check_files() {
	char check;
	ifstream mem_file("/systeminfo-files");							// systeminfo-files is a directory
	if(mem_file.good()==false) {
		cout << "Not found \"/systeminfo-files\"" << endl;
		cout << "Create this folder? [y/n]... " << endl;
		cin >> check;
		switch(check) {
		case 't':
			system("sudo mkdir /systeminfo-files");
			system("sudo chmod 777 /systeminfo-files");
			break;
		case 'n':
			exit(0);
		default:
			exit(0);
		}
	}
	else {
		cout << "> All files is integrated ✔" << endl;
	}
}

void output_help() {
	cout << "Usage: system [optional_option]" << endl;
	cout << "Options:" << endl;
	cout << "	-m	--memory		Information of memory RAM and Swap" << endl;
	cout << "	-M	--memory-megabyte	Information of memory RAM and Swap" << endl;
	cout << "					in megabyte form" << endl;
	cout << "	-s	--system		Information of system and hardware" << endl;
	cout << "	-h	--hostname		Information of hostname" << endl;
	cout << "	-c	--cpu			Information of cpu only" << endl;
	cout << "		--check-files		Check integration files" << endl;
	cout << "		--help			Information of program and help panel" << endl;
	cout << "		--version		Show version information" << endl;
}
