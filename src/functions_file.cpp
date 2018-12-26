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

void cpu_file() {
	const string input_value = "/systeminfo-files/systeminfo-cpu.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	int length = value.length();

	cout << "CPU:				";
	for(int i = 1; i < length; i++) {
		cout << value[i];
	}
	cout << endl;
}

void shell_file() {
	const string input_value = "/systeminfo-files/systeminfo-shell.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

		if(value == "/bin/zsh")			cout << "Shell:				Z-Shell (" << value << ")" << endl;
		else if(value == "/bin/bash")	cout << "Shell:				Bash (" << value << ")" << endl;
		else if(value == "/bin/sh")		cout << "Shell:				Sh (" << value << ")" << endl;
		else if(value == "/bin/dash")	cout << "Shell:				Dash (" << value << ")" << endl;
		else if(value == "/bin/ksh")	cout << "Shell:				Ksh (" << value << ")" << endl;
		else if(value == "/bin/rsh")	cout << "Shell:				Rsh (" << value << ")" << endl;
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

string ssh() {
	const string input_value = "/systeminfo-files/systeminfo-ssh.txt";
	int line = 1;

	string value, value_2;
	value = open_file(input_value, line);

	if(value == "active(running)")	return "Enabled";
	if(value == "inactive(dead)")	return "Disabled";
	else							return "N/A";
}
