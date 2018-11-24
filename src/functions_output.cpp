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

using namespace std;

void output_all() {

	char* shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

	errno = 0;
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

	errno = 0;
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

	errno = 0;
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

void output_help() {
	cout << "Usage: system [optional_option]" << endl;
	cout << "Options:" << endl;
	cout << "	-m	--memory		Information of memory RAM and Swap" << endl;
	cout << "	-s	--system		Information of system and hardware" << endl;
	cout << "	-h	--hostname		Information of hostname" << endl;
	cout << "	-c	--cpu			Information of cpu only" << endl;
	cout << "		--help			Information of program and help panel" << endl;
	cout << "		--version		Show version information" << endl;
}
