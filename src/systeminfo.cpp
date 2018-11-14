//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {

	cout << "OS Name:" << endl;
	system("uname -o");
	cout << endl;

	cout << "Kernel version:" << endl;
	system("uname -r");
	cout << endl;

	cout << "System architecture:" << endl;
	system("arch");
	cout << endl;

	cout << "Shell:" << endl;
	system("echo $SHELL");
	cout << endl;

	cout << "Hostname:" << endl;
	system("hostname");
	cout << endl;

	cout << "Uptime:" << endl;
	system("uptime -p");
	cout << endl;
}
