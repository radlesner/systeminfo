/*
 * functions_file.cpp
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

void distribution_file() {
	string distro_line;
		int distro_nr_line=1;

		string distro;

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

		cout << "Distribution:		" << distro << endl;
}

void cpu_file() {
	string cpu_line;
		int cpu_nr_line=1;

		string cpu;

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

		cout << "CPU:	    		       " << cpu << endl;
}

void shell_file() {
	string shell_line;
		int shell_nr_line=1;

		string shell_name;

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

		if(shell_name == "/bin/zsh")		cout << "Shell:				Z-Shell (" << shell_name << ")" << endl;
		else if(shell_name == "/bin/bash")	cout << "Shell:				Bash (" << shell_name << ")" << endl;
		else if(shell_name == "/bin/sh")	cout << "Shell:				Sh (" << shell_name << ")" << endl;
		else if(shell_name == "/bin/dash")	cout << "Shell:				Dash (" << shell_name << ")" << endl;
		else if(shell_name == "/bin/ksh")	cout << "Shell:				Ksh (" << shell_name << ")" << endl;
		else if(shell_name == "/bin/rsh")	cout << "Shell:				Rsh (" << shell_name << ")" << endl;
		else								cout << "Shell:				" << shell_name << endl;
}

void cores_file() {
	string cores_line;
		int cores_nr_line=1;

		int cores_int;
		string cores;

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

		if(cores_int == 1)
			cout << "Cores:		  		" << cores_int << " core" << endl;
		else
			cout << "Cores:		  		" << cores_int << " cores" << endl;
}

void swap_file() {
	string swap_line;
		int swap_nr_line=1;

		double swap_total_conventer, swap_total, swap_free_conventer, swap_free;
		string swap_total_string, swap_free_string;

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

		cout << "Swap Total/Free:		" << swap_total << " GB/" << swap_free << " GB" << endl;
}

void uptime_file() {
	string uptime_line;
		int uptime_nr_line=1;

		string uptime;

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

		cout << "Uptime:			       " << uptime << endl;
}
