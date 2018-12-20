/*
 * functions_file.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include "functions_file.h"
#include "function_open_file.h"

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

string cpu_frequency() {
	const string input_value = "/systeminfo-files/systeminfo-cpu-frequency.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

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
