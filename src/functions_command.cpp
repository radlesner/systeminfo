/*
 * functions_command.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include "functions_command.h"
#include "functions_file.h"

using namespace std;

void command_check_folder_exist()
{
	string home_path = getenv("HOME");
	char check;
	string path_file = home_path + "/.systeminfo-files/";
	fstream mem_file(path_file, ios::in); //---------------/ systeminfo-files is a directory /---------------
	if(mem_file.good() == false)
	{
		cout << "Not found folder \"" << home_path << "/.systeminfo-files\"" << endl;
		cout << "Create folder \"systeminfo-files\"? [y/n]... ";
		cin >> check;
		switch(check)
		{
		case 'y':
			cout << "------------------------------------------------------------------------" << endl;
			system("mkdir /$HOME/.systeminfo-files"); 					cout << "Creating \"systeminfo-files\" folder,.. done." << endl;
			system("mkdir /$HOME/.systeminfo-files/logs");				cout << "Creating \"logs\" folder,.............. done" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			break;
		case 'n':
			exit(0);
		default:
			exit(0);
		}
	}
}

void command_activate()
{
	ifstream mem_file("systeminfo_script.sh");
	if(mem_file.good() == true)	system("./systeminfo_script.sh");
	else						system("cd /usr/bin/ && ./systeminfo_script.sh");
}

void command_remove()
{
	//system("cd /$HOME/.systeminfo-files && rm -f *.*");
}