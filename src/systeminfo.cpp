//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.5.6
// Copyright   : Your copyright notice
// Description : systeminfo in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/utsname.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <time.h>

#include "functions_output.h"
#include "functions_file.h"
#include "functions_command.h"
#include "functions_file_memory.h"
#include "functions_output_memory_swap.h"

using namespace std;

void output_version() {
	string version = "0.5.6";
	cout << "systeminfo 2018, v" << version << endl;
}

int main(int argc, char **argv) {
	command_check_folder_exist();
	command_activate();
	if(argc > 1) {
		if(!strcmp(argv[1], "-m") || !strcmp(argv[1], "--memory"))					output_memory();
		else if(!strcmp(argv[1], "-M") || !strcmp(argv[1], "--memory-megabyte"))	output_memory_megabyte();
		else if(!strcmp(argv[1], "-s") || !strcmp(argv[1], "--system"))				output_system();
		else if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--hostname"))			output_hostname_only();
		else if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "--cpu"))				output_cpu_only();
		else if(!strcmp(argv[1], "--check-files"))									output_check_files();
		else if(!strcmp(argv[1], "--version"))										output_version();
		else if(!strcmp(argv[1], "--help"))											output_help();
		else {
			cout << "Bad option: " << argv[1] << endl << endl;
			output_help();
		}
	}
	else
		output_all();
	command_remove();

	return 0;
}
