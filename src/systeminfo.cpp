//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.2.7
// Copyright   : Your copyright notice
// Description : systeminfo in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/utsname.h>

using namespace std;

string osname, distro, kernel, architecture, cpu, hostname, uptime;
string shell_name;

void uptime_file();
void distribution_file();
void cpu_file();
void shell_file();

int main(void) {
	system("cd /systeminfo-files && uptime -p >> systeminfo-uptime.txt");
	system("cd /systeminfo-files && lsb_release -i | cut -d\\: -f2 >> systeminfo-distro.txt");
	system("cd /systeminfo-files && cat /proc/cpuinfo | grep -i \"name\" --max-count=1 | cut -d\\: -f2 >> systeminfo-cpu.txt");
	system("cd /systeminfo-files && echo $SHELL >> systeminfo-shell.txt");

	uptime_file();
	distribution_file();
	cpu_file();
	shell_file();

	char* shell;
	shell = getenv ("SHELL");

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
	cout << "CPU:	    		       " << cpu << endl;
	if(shell_name == "/bin/zsh")
		cout << "Shell:				Z-Shell (" << shell_name << ")" << endl;
	if(shell_name == "/bin/bash")
		cout << "Shell:				Bash (" << shell_name << ")" << endl;
	if(shell_name == "/bin/sh")
		cout << "Shell:				Sh (" << shell_name << ")" << endl;
	if(shell_name == "/bin/dash")
		cout << "Shell:				Dash (" << shell_name << ")" << endl;
	if(shell_name == "/bin/ksh")
		cout << "Shell:				Ksh (" << shell_name << ")" << endl;
	if(shell_name == "/bin/rsh")
		cout << "Shell:				Rsh (" << shell_name << ")" << endl;
	else
		cout << "Shell:				" << shell_name << endl;
	cout << "Hostname:			" << buffer.nodename << endl;
	cout << "Uptime:				" << uptime << endl;

	system("rm /systeminfo-files/systeminfo-uptime.txt");
	system("rm /systeminfo-files/systeminfo-distro.txt");
	system("rm /systeminfo-files/systeminfo-cpu.txt");
	system("rm /systeminfo-files/systeminfo-shell.txt");

	return 0;
}

void uptime_file() {
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

void distribution_file() {
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

void cpu_file() {
	string cpu_line;
		int cpu_nr_line=1;

		ifstream cpu_file("/systeminfo-files/systeminfo-cpu.txt");

		if(cpu_file.good()==false)
			cout<<"Error 002: Not found file \"systeminfo-cpu.txt\"" << endl;

		while (getline(cpu_file, cpu_line)) {
			switch (cpu_nr_line) {
				case 1: cpu=cpu_line; break;
			}
			cpu_nr_line++;
		}

		cpu_file.close();
}

void shell_file() {
	string shell_line;
		int shell_nr_line=1;

		ifstream shell_file("/systeminfo-files/systeminfo-shell.txt");

		if(shell_file.good()==false)
			cout<<"Error 002: Not found file \"systeminfo-shell.txt\"" << endl;

		while (getline(shell_file, shell_line)) {
			switch (shell_nr_line) {
				case 1: shell_name=shell_line; break;
			}
			shell_nr_line++;
		}

		shell_file.close();
}
