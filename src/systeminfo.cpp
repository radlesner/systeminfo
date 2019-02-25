//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.8.2
// Copyright   : GNU General Public License (GPL)
// Description : systeminfo in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstring>

#include "functions_output.h"
#include "functions_file_memory.h"
#include "functions_file_swap.h"
#include "functions_command.h"

using namespace std;

void output_version() {
	cout << "systeminfo 2018, v1.1" << endl; // Program versions also change in the function with logs
	cout << "Compile date...............: " << __DATE__ << endl;
	cout << "Compile time...............: " << __TIME__ << endl;
}

int main(int argc, char** argv) {
	command_check_folder_exist();
	command_activate();
	if(argc > 1) {
		if(!strcmp(argv[1], "-g") || !strcmp(argv[1], "--gigabyte")) {
			mem_file(0);
			swap_file(0);
		}
		else if(!strcmp(argv[1], "-m") || !strcmp(argv[1], "--megabyte")) {
			mem_megabyte_file();
			swap_megabyte_file();
		}
		else if(!strcmp(argv[1], "-s") || !strcmp(argv[1], "--system"))				output_system();
		else if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "--cpu"))				output_cpu_only();
		else if(!strcmp(argv[1], "-n") || !strcmp(argv[1], "--network"))			output_network();
		else if(!strcmp(argv[1], "-t") || !strcmp(argv[1], "--monitor"))			output_monitor(argc, argv);
		else if(!strcmp(argv[1], "--check-files"))									output_check_files();
		else if(!strcmp(argv[1], "--version"))										output_version();
		else if(!strcmp(argv[1], "--help"))											output_help();
		else if(!strcmp(argv[1], "--log"))											output_save_file();
		else if(!strcmp(argv[1], "--"))												output_all();
		else if(!strcmp(argv[1], "-"))												output_all();
		else {
			if(argc > 3)		cout << "Bad option: " << argv[1] << " " << argv[2] << " " << argv[3] << endl;
			else if(argc > 2)	cout << "Bad option: " << argv[1] << " " << argv[2] << endl;
			else				cout << "Bad option: " << argv[1] << endl;
			output_help();
		}
	}
	else 	output_all();
	command_remove();

	return 0;
}