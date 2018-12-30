//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.8
// Copyright   : GNU General Public License (GPL)
// Description : systeminfo in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstring>

#include "functions_output.h"
#include "functions_output_memory_swap.h"
#include "functions_command.h"

using namespace std;

void output_version() {
	string version = "0.8";
	cout << "systeminfo 2018, v" << version << endl;
	cout << "Compiled: " << __DATE__ << " | " << __TIME__ << " | " << __FILE__ << endl;
}

int main(int argc, char** argv) {
	command_check_folder_exist();
	command_activate();
	if(argc > 1) {
		if(argc > 2)
			if(!strcmp(argv[2], "-l") || !strcmp(argv[2], "--logo"))				output_logo();
		if(!strcmp(argv[1], "-m") || !strcmp(argv[1], "--memory"))					output_memory();
		else if(!strcmp(argv[1], "-M") || !strcmp(argv[1], "--memory-megabyte"))	output_memory_megabyte();
		else if(!strcmp(argv[1], "-s") || !strcmp(argv[1], "--system"))				output_system();
		else if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "--cpu"))				output_cpu_only();
		else if(!strcmp(argv[1], "-l") || !strcmp(argv[1], "--logo")) {
			output_logo();
			output_all();
		}
		else if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--ssh"))				output_ssh_info();
		else if(!strcmp(argv[1], "-t") || !strcmp(argv[1], "--monitor"))			output_monitor(argc, argv);
		else if(!strcmp(argv[1], "--check-files"))									output_check_files();
		else if(!strcmp(argv[1], "--version"))										output_version();
		else if(!strcmp(argv[1], "--help"))											output_help();
		else if(!strcmp(argv[1], "--"))												output_all();
		else if(!strcmp(argv[1], "-"))												output_all();
		else {
			if(argc > 2)	cout << "Bad option: " << argv[1] << " " << argv[2] << endl;
			else			cout << "Bad option: " << argv[1]<< endl;
			output_help();
		}
	}
	else 	output_all();
	command_remove();

	return 0;
}