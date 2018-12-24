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

int cpu_frequency() {
	const string input_value = "/systeminfo-files/systeminfo-cpu-frequency.txt";
	const string input_value_cores = "/systeminfo-files/systeminfo-cores.txt";
	int line = 4;
	int line_cores = 1;
	double sum;

	string value_cores;
	value_cores = open_file(input_value_cores, line_cores);
	int value_cores_int = atoi(value_cores.c_str());

	string read_value[128];
	int value[128];
	for(int i = 0; i < value_cores_int; i++) {
		read_value[i] = open_file(input_value, line++);
		value[i] = atoi(read_value[i].c_str());
	}

	for(int a = 0; a < value_cores_int; a++) {
		sum = sum + value[a];
	}

	sum = sum / value_cores_int / 1000;

	return sum;
}

int cpu_frequency_max() {
	const string input_value = "/systeminfo-files/systeminfo-cpu-frequency.txt";
	const int line = 2;

	string read_value;
	read_value = open_file(input_value, line);
	int value = atoi(read_value.c_str());

	return value;
}

int cpu_frequency_min() {
	const string input_value = "/systeminfo-files/systeminfo-cpu-frequency.txt";
	const int line = 3;

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
