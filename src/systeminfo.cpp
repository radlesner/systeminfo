//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.2.4
// Copyright   : Your copyright notice
// Description : systeminfo in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/utsname.h>

using namespace std;

string osname, kernel, architecture, shell, hostname, uptime;

void openfile();
void distribution();

int main(void) {
	system("cd /systeminfo-files && uptime -p >> systeminfo-uptime.txt");
	system("cd /systeminfo-files && lsb_release -i >> systeminfo-distro.txt");

	openfile();

	char* Shell;
	Shell = getenv ("SHELL");

	struct utsname buffer;

	errno = 0;
		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "OS Name:			" << buffer.sysname << endl;
	distribution();
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
	string line;
	int nr_line=1;

	ifstream file("/systeminfo-files/systeminfo-uptime.txt");

	if(file.good()==false)
		cout<<"Error 001: Not found file \"systeminfo-uptime.txt\"";

	while (getline(file, line)) {
		switch (nr_line) {
			case 1: uptime=line; break;
		}
		nr_line++;
	}

	file.close();
}

void distribution() {
	fstream plik("/systeminfo-files/systeminfo-distro.txt");
	string tekst;
	while(!plik.eof()) {
		getline(plik, tekst);
		if(!(string::npos == tekst.find("Ubuntu"))) {
			cout << "Distribution:			Ubuntu" << endl;
			break;
		}
		if(!(string::npos == tekst.find("Debian"))) {
			cout << "Distribution:			Debian" << endl;
			break;
		}
		if(!(string::npos == tekst.find("Ubuntu"))) {
			cout << "Distribution:			Ubuntu" << endl;
			break;
		}
		if(!(string::npos == tekst.find("ManjaroLinux"))) {
			cout << "Distribution:			Manjaro" << endl;
			break;
		}
		if(!(string::npos == tekst.find("ArchLinux"))) {
			cout << "Distribution:			ArchLinux" << endl;
			break;
		}
		if(!(string::npos == tekst.find("openSUSE project"))) {
			cout << "Distribution:			openSUSE" << endl;
			break;
		}
		if(!(string::npos == tekst.find("Fedora"))) {
			cout << "Distribution:			Fedora" << endl;
			break;
		}
		else {
			cout << "Distribution:			Unknown distribution or not instaled \"lsb-release\"" << endl;
			break;
		}
	}
}
