/*
 * functions_file.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include "functions_file.h"
#include "functions_file_operations.h"

using namespace std;

string distribution_file() {
	const string input_value = "/systeminfo-files/systeminfo-distro.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	return value;
}

string release_system() {
	const string input_value = "/systeminfo-files/systeminfo-distro.txt";
	const int line = 2;

	string value;
	value = open_file(input_value, line);

	return value;
}

void cpu_file() {
	const string input_value = "/systeminfo-files/systeminfo-cpu.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	cout << "CPU:				" << value << endl;
}

void architecture() {
	const string input_value = "/systeminfo-files/systeminfo-distro.txt";
	const string bit32 = "32 Bits";
	const string bit64 = "64 Bits";
	const string arm32 = "ARM 32 Bits";
	const string arm64 = "ARM 64 Bits";

	string arch, bits;
	arch = open_file(input_value, 3);
	bits = open_file(input_value, 4);

	if(bits.empty() == true)
		cout << "System architecture:		" << arch << endl;
	else
		cout << "System architecture:		" << bits << " Bits (" << arch << ")" << endl;
}

void shell_file() {
	const string input_value = "/systeminfo-files/systeminfo-shell.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

		if(value == "/bin/zsh" || value == "/usr/bin/zsh")			cout << "Shell:				Z-Shell (" << value << ")" << endl;
		else if(value == "/bin/bash" || value == "/usr/bin/bash")	cout << "Shell:				Bash (" << value << ")" << endl;
		else if(value == "/bin/sh" || value == "/usr/bin/sh")		cout << "Shell:				Sh (" << value << ")" << endl;
		else if(value == "/bin/dash" || value == "/usr/bin/dash")	cout << "Shell:				Dash (" << value << ")" << endl;
		else if(value == "/bin/ksh" || value == "/usr/bin/ksh")		cout << "Shell:				Ksh (" << value << ")" << endl;
		else if(value == "/bin/rsh" || value == "/usr/bin/rsh")		cout << "Shell:				Rsh (" << value << ")" << endl;
		else							cout << "Shell:				" << value << endl;
}

void cores_file() {
	const string input_value = "/systeminfo-files/systeminfo-cores.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	if(value == "1")
		cout << "Cores:		  		" << value << " core" << endl;
	else
		cout << "Cores:		  		" << value << " cores" << endl;
}

void freq_check_system(string distro) {
	if(distro == "Raspbian" || cpu_frequency() == 1)	cout << "CPU Frequency:			N/A" << endl;
	else cout << "CPU Frequency:			" << cpu_frequency() << " MHz" << endl;
}

int cpu_frequency() {
	const string input_value = "/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq";
	int line = 1;

	string read_value;
	int value;
	read_value = open_file(input_value, line);

	if(read_value == "N/A") return 1;

	value = atoi(read_value.c_str()) / 1000;

	return value;
}

int cpu_frequency_max() {
	const string input_value = "/systeminfo-files/systeminfo-cpu-frequency_max.txt";
	const int line = 1;

	string read_value;
	read_value = open_file(input_value, line);
	int value = atoi(read_value.c_str());

	return value;
}

int cpu_frequency_min() {
	const string input_value = "/systeminfo-files/systeminfo-cpu-frequency_min.txt";
	const int line = 1;

	string read_value;
	read_value = open_file(input_value, line);
	int value = atoi(read_value.c_str());

	return value;
}

string user_file() {
	const string input_value = "/systeminfo-files/systeminfo-user.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	return value;
}

string uptime_file() {
	const string input_value = "/systeminfo-files/systeminfo-uptime.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	return value;
}