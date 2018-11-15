//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     :
// Copyright   : Your copyright notice
// Description : systeminfo in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

string osname, kernel, architecture, shell, hostname, uptime;

int main() {
	system("cd ~/");
	system("uname -o >> .systeminfo-file.txt");
	system("uname -r >> .systeminfo-file.txt");
	system("arch >> .systeminfo-file.txt");
	system("echo $SHELL >> .systeminfo-file.txt");
	system("hostname >> .systeminfo-file.txt");
	system("uptime -p >> .systeminfo-file.txt");

	string line;
		    int nr_line=1;

		    fstream file;
		    file.open(".systeminfo-file.txt", ios::in);

		    if(file.good()==false)
		    	cout<<"Error 001: Not found file \".systeminfo-file.txt\"";

		    while (getline(file, line)) {
		        switch (nr_line) {
		            case 1: osname=line; break;
		            case 2: kernel=line; break;
		            case 3: architecture=line; break;
		            case 4: shell=line; break;
		            case 5: hostname=line; break;
		            case 6: uptime=line; break;
		        }
		        nr_line++;
		    }

		    file.close();

		    cout << "OS Name:			" << osname << endl;
			cout << "Kernel version:			" << kernel << endl;
			cout << "System architecture:		" << architecture << endl;
			cout << "Shell:				" << shell << endl;
			cout << "Hostname:			" << hostname << endl;
			cout << "Uptime:				" << uptime << endl;

			system("rm .systeminfo-file.txt");

		    return 0;
}
