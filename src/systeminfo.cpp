//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.4
// Copyright   : Your copyright notice
// Description : systeminfo in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/utsname.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <cstring>

using namespace std;

string osname, distro, kernel, architecture, cpu, cores, shell_name, hostname, uptime;
string mem_max_string, mem_available_string;
double mem_max_conventer, mem_max, mem_available_conventer, mem_available, mem_used;
string swap_total_string, swap_free_string;
double swap_total_conventer, swap_total, swap_free_conventer, swap_free;

int cores_int;

void output_all();
void output_system();
void output_memory();
void output_hostname_only();
void output_cpu_only();
void output_help();

void uptime_file();
void distribution_file();
void cpu_file();
void shell_file();
void cores_file();
void mem_file();
void swap_file();

int main(int argc, char **argv) {
	system("cd /systeminfo-files && uptime -p | cut -d\p -f2 >> systeminfo-uptime.txt");
	system("cd /systeminfo-files && lsb_release -i | cut -d\\: -f2 >> systeminfo-distro.txt");
	system("cd /systeminfo-files && cat /proc/cpuinfo | grep -i \"name\" --max-count=1 | cut -d\\: -f2 >> systeminfo-cpu.txt");
	system("cd /systeminfo-files && echo $SHELL >> systeminfo-shell.txt");
	system("cd /systeminfo-files && lscpu | grep -i \"CPU(s):\" --max-count=1 | cut -d\\: -f2 | tr -d ' '  >> systeminfo-cores.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"MemTotal: \" --max-count=1 | cut -d\\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-mem.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"MemAvailable: \" --max-count=1 | cut -d\\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-mem.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"SwapTotal: \" --max-count=1 | cut -d\\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-swap.txt");
	system("cd /systeminfo-files && cat /proc/meminfo | grep -i \"SwapFree: \" --max-count=1 | cut -d\\: -f2 | tr -d ' ' | tr -d 'kB' >> systeminfo-swap.txt");

	if(argc > 1) {
		if(!strcmp(argv[1], "-m") || !strcmp(argv[1], "--memory"))			output_memory();
		else if(!strcmp(argv[1], "-s") || !strcmp(argv[1], "--system"))		output_system();
		else if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--hostname"))	output_hostname_only();
		else if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "--cpu"))		output_cpu_only();
		else if(!strcmp(argv[1], "--help"))		output_help();
		else {
			cout << "Bad option: " << argv[1] << endl << endl;
			output_help();
		}
	}
	else output_all();

	system("cd /systeminfo-files && rm systeminfo-uptime.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-distro.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-cpu.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-cores.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-shell.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-mem.txt >> systeminfo-errors.txt");
	system("cd /systeminfo-files && rm systeminfo-swap.txt >> systeminfo-errors.txt");

	return 0;
}

void output_all() {
	uptime_file();
	distribution_file();
	cpu_file();
	shell_file();
	cores_file();
	mem_file();
	swap_file();

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
	if(cores_int == 1)
		cout << "Cores:		  		" << cores_int << " core" << endl;
	else
		cout << "Cores:		  		" << cores_int << " cores" << endl;
	cout.precision(3);
	cout << "RAM Total/Available/Used:	" << mem_max << " GB/" << mem_available << " GB/" << mem_used << " GB" << endl;
	cout << "Swap Total/Free:		" << swap_total << " GB/" << swap_free << " GB" << endl;
		if(shell_name == "/bin/zsh")		cout << "Shell:				Z-Shell (" << shell_name << ")" << endl;
		else if(shell_name == "/bin/bash")	cout << "Shell:				Bash (" << shell_name << ")" << endl;
		else if(shell_name == "/bin/sh")	cout << "Shell:				Sh (" << shell_name << ")" << endl;
		else if(shell_name == "/bin/dash")	cout << "Shell:				Dash (" << shell_name << ")" << endl;
		else if(shell_name == "/bin/ksh")	cout << "Shell:				Ksh (" << shell_name << ")" << endl;
		else if(shell_name == "/bin/rsh")	cout << "Shell:				Rsh (" << shell_name << ")" << endl;
		else								cout << "Shell:				" << shell_name << endl;
	cout << "Hostname:			" << buffer.nodename << endl;
	cout << "Uptime:			       " << uptime << endl;
}

void output_system() {
	distribution_file();
	cpu_file();
	shell_file();
	cores_file();

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
	if(cores_int == 1)
		cout << "Cores:		  		" << cores_int << " core" << endl;
	else
		cout << "Cores:		  		" << cores_int << " cores" << endl;
	if(shell_name == "/bin/zsh")		cout << "Shell:				Z-Shell (" << shell_name << ")" << endl;
	else if(shell_name == "/bin/bash")	cout << "Shell:				Bash (" << shell_name << ")" << endl;
	else if(shell_name == "/bin/sh")	cout << "Shell:				Sh (" << shell_name << ")" << endl;
	else if(shell_name == "/bin/dash")	cout << "Shell:				Dash (" << shell_name << ")" << endl;
	else if(shell_name == "/bin/ksh")	cout << "Shell:				Ksh (" << shell_name << ")" << endl;
	else if(shell_name == "/bin/rsh")	cout << "Shell:				Rsh (" << shell_name << ")" << endl;
	else								cout << "Shell:				" << shell_name << endl;
}

void output_memory() {
	mem_file();
	swap_file();

	cout.precision(3);
	cout << "RAM Total:			" << mem_max << " GB" << endl;
	cout << "RAM Available:			" << mem_available << " GB" << endl;
	cout << "RAM Used:			" << mem_used << " GB" << endl;
	cout << "Swap Total:			" << swap_total << " GB" << endl;
	cout << "Swap Free:			" << swap_free << " GB" << endl;
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

	cout << "CPU:	    		       " << cpu << endl;
	if(cores_int == 1)
		cout << "Cores:		  		" << cores_int << " core" << endl;
	else
		cout << "Cores:		  		" << cores_int << " cores" << endl;
}

void output_help() {
	cout << "Usage: system [option] #not required" << endl;
	cout << "Options:" << endl;
	cout << "	-m	--memory		Information of memory RAM and Swap" << endl;
	cout << "	-s	--system		Information of system and hardware" << endl;
	cout << "	-h	--hostname		Information of hostname" << endl;
	cout << "	-c	--cpu			Information of cpu only" << endl;
	cout << "		--help			Information of program and help panel" << endl;
}

void uptime_file() {
	string uptime_line;
	int uptime_nr_line=1;

	ifstream uptime_file("/systeminfo-files/systeminfo-uptime.txt");

	if(uptime_file.good()==false)
		cout << "Error 001: Not found file \"systeminfo-uptime.txt\"" << endl;

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
			cout << "Error 002: Not found file \"systeminfo-distro.txt\"" << endl;

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
			cout << "Error 003: Not found file \"systeminfo-cpu.txt\"" << endl;

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
			cout << "Error 004: Not found file \"systeminfo-shell.txt\"" << endl;

		while (getline(shell_file, shell_line)) {
			switch (shell_nr_line) {
				case 1: shell_name=shell_line; break;
			}
			shell_nr_line++;
		}

		shell_file.close();
}

void cores_file() {
	string cores_line;
		int cores_nr_line=1;

		ifstream cores_file("/systeminfo-files/systeminfo-cores.txt");

		if(cores_file.good()==false)
			cout << "Error 005: Not found file \"systeminfo-cores.txt\"" << endl;

		while (getline(cores_file, cores_line)) {
			switch (cores_nr_line) {
				case 1: cores=cores_line; break;
			}
			cores_nr_line++;
		}

		cores_file.close();

		istringstream corecpu(cores);
		corecpu >> cores_int;
}

void mem_file() {
	string mem_line;
		int mem_nr_line=1;

		ifstream mem_file("/systeminfo-files/systeminfo-mem.txt");

		if(mem_file.good()==false)
			cout << "Error 006: Not found file \"systeminfo-mem.txt\"" << endl;

		while (getline(mem_file, mem_line)) {
			switch (mem_nr_line) {
				case 1: mem_max_string=mem_line; break;
				case 2: mem_available_string=mem_line; break;
			}
			mem_nr_line++;
		}

		mem_file.close();

		istringstream memmax(mem_max_string);
		memmax >> mem_max_conventer;

		mem_max = mem_max_conventer / 1024 / 1024;


		istringstream memavailable(mem_available_string);
		memavailable >> mem_available_conventer;

		mem_available = mem_available_conventer / 1024 / 1024;

		mem_used = mem_max - mem_available;
}

void swap_file() {
	string swap_line;
		int swap_nr_line=1;

		ifstream swap_file("/systeminfo-files/systeminfo-swap.txt");

		if(swap_file.good()==false)
			cout << "Error 007: Not found file \"systeminfo-swap.txt\"" << endl;

		while (getline(swap_file, swap_line)) {
			switch (swap_nr_line) {
				case 1: swap_total_string=swap_line; break;
				case 2: swap_free_string=swap_line; break;
			}
			swap_nr_line++;
		}

		swap_file.close();

		istringstream swaptotal(swap_free_string);
		swaptotal >> swap_total_conventer;

		swap_total = swap_total_conventer / 1024 / 1024;


		istringstream swapfree(swap_free_string);
		swapfree >> swap_free_conventer;

		swap_free = swap_free_conventer / 1024 / 1024;
}
