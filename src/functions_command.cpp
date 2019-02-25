/*
 * functions_command.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include "functions_command.h"
#include "functions_file.h"

using namespace std;

void command_check_folder_exist() {
	string user = getenv("USER");
	char check;
	ifstream mem_file("/systeminfo-files"); //---------------/ systeminfo-files is a directory /---------------
	if(mem_file.good() == false) {
		cout << "Not found folder \"/systeminfo-files\"" << endl;
		cout << "Create folder /systeminfo-files? [y/n]... ";
		cin >> check;
		switch(check) {
		case 'y':
			cout << "------------------------------------------------------------------------" << endl;
			if (user == "root") {
				system("mkdir /systeminfo-files"); 					cout << "Creating \"systeminfo-files\" folder,.. done." << endl;
				system("mkdir /systeminfo-files/logs");				cout << "Creating \"logs\" folder,.............. done" << endl;
				system("chmod 777 /systeminfo-files");				cout << "Granting access /systeminfo-files,... done." << endl;
				system("chmod 777 /systeminfo-files/logs");			cout << "Granting access /logs,............... done." << endl;
			}
			else {
				system("sudo mkdir /systeminfo-files"); 			cout << "Creating \"systeminfo-files\" folder,.. done." << endl;
				system("sudo mkdir /systeminfo-files/logs");		cout << "Creating \"logs\" folder,.............. done" << endl;
				system("sudo chmod 777 /systeminfo-files");			cout << "Granting access /systeminfo-files,... done." << endl;
				system("sudo chmod 777 /systeminfo-files/logs");	cout << "Granting access /logs,............... done." << endl;
			}
			cout << "------------------------------------------------------------------------" << endl;
			break;
		case 'n':
			exit(0);
		default:
			exit(0);
		}
	}
}

void command_activate() {
	system("./systeminfo_script.sh");
}

void command_remove() {
	system("./systeminfo_remove_script.sh");
}