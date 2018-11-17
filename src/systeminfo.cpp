//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.2.5
// Copyright   : Your copyright notice
// Description : systeminfo in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/utsname.h>

using namespace std;

string osname, distro, kernel, architecture, shell, hostname, uptime;

void openfile();
void distribution();

int main(void) {
	system("cd /systeminfo-files && uptime -p >> systeminfo-uptime.txt");
	system("cd /systeminfo-files && lsb_release -i | cut -d\: -f2 >> systeminfo-distro.txt");

	openfile();
	distribution();

	char* Shell;
	Shell = getenv ("SHELL");

	struct utsname buffer;

	errno = 0;
		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "OS Name:			" << buffer.sysname << endl;
	cout << "Distribution:		" << distro << endl;
	cout << "Kernel version:			" << buffer.release << endl;
	cout << "System architecture:		" << buffer.machine << endl;
	if (Shell!=NULL) {
		cout << "Shell:				" << Shell << endl;
	}
	cout << "Hostname:			" << buffer.nodename << endl;
	cout << "Uptime:				" << uptime << endl;

	system("rm /systeminfo-files/systeminfo-uptime.txt");
	system("rm /systeminfo-files/systeminfo-distro.txt");

	return 0;
}

void openfile() {
	string uptime_line;
	int uptime_nr_line=1;

	ifstream uptime_file("/systeminfo-files/systeminfo-uptime.txt");

	if(uptime_file.good()==false)
		cout<<"Error 001: Not found file \"systeminfo-uptime.txt\"" << endl;

	while (getline(uptime_file, uptime_line)) {
		switch (uptime_nr_line) {
			case 1: uptime=uptime_line; break;
		}
		uptime_nr_line++;
	}

	uptime_file.close();
}

void distribution() {
	string distro_line;
		int distro_nr_line=1;

		ifstream distro_file("/systeminfo-files/systeminfo-distro.txt");

		if(distro_file.good()==false)
			cout<<"Error 002: Not found file \"systeminfo-distro.txt\"" << endl;

		while (getline(distro_file, distro_line)) {
			switch (distro_nr_line) {
				case 1: distro=distro_line; break;
			}
			distro_nr_line++;
		}

		distro_file.close();
}
