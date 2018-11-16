//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.2.3
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
	system("cd /systeminfo-files && pwd && uptime -p >> systeminfo-file.txt");

	//-----------------------------------------------------------------------------------------------
	string line;
				    int nr_line=1;

				    //fstream file;
				    ifstream file("/systeminfo-files/systeminfo-file.txt");
				    //file.open(".systeminfo-file.txt", ios::in);

				    if(file.good()==false)
				    	cout<<"Error 001: Not found file \"systeminfo-file.txt\"";

				    while (getline(file, line)) {
				        switch (nr_line) {
				            case 1: uptime=line; break;
				        }
				        nr_line++;
				    }

				    file.close();
	//-----------------------------------------------------------------------------------------------

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
	cout << "Uptime:				" << uptime << endl;

	system("rm /systeminfo-files/systeminfo-file.txt");

	return 0;
}
