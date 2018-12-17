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

	string value;
	value = open_file(input_value);

	return value;
}

void cpu_file() {
	const string input_value = "/systeminfo-files/systeminfo-cpu.txt";

	string value;
	value = open_file(input_value);

	int length = value.length();

	cout << "CPU:				";
	for(int i = 1; i < length; i++) {
		cout << value[i];
	}
	cout << endl;
}

void shell_file() {
	const string input_value = "/systeminfo-files/systeminfo-shell.txt";

	string value;
	value = open_file(input_value);

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

	string value;
	value = open_file(input_value);

	if(value == "1")
		cout << "Cores:		  		" << value << " core" << endl;
	else
		cout << "Cores:		  		" << value << " cores" << endl;
}

string user_file() {
	const string input_value = "/systeminfo-files/systeminfo-user.txt";

	string value;
	value = open_file(input_value);

	return value;
}

string uptime_file() {
	const string input_value = "/systeminfo-files/systeminfo-uptime.txt";

	string value;
	value = open_file(input_value);

	return value;
}
