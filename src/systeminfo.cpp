//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.2.2
// Copyright   : Your copyright notice
// Description : systeminfo in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

using namespace std;

string osname, kernel, architecture, shell, hostname, uptime;

int main(void) {

	char* Shell;
	Shell = getenv ("SHELL");

	struct utsname buffer;

	errno = 0;
		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "OS Name:			" << buffer.sysname << endl;
	cout << "Kernel version:			" << buffer.release << endl;
	cout << "System architecture:		" << buffer.machine << endl;
	if (Shell!=NULL) {
		cout << "Shell:				" << Shell << endl;
	}
	cout << "Hostname:			" << buffer.nodename << endl;

	return 0;
}
