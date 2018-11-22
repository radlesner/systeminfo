//============================================================================
// Name        : systeminfo.cpp
// Author      : Radek Lesner
// Version     : 0.5
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

#include "functions_output.h"
#include "functions_file.h"
#include "functions_command.h"

using namespace std;

int main(int argc, char **argv) {
	command_activate();
	if(argc > 1) {
		if(!strcmp(argv[1], "-m") || !strcmp(argv[1], "--memory"))			output_memory();
		else if(!strcmp(argv[1], "-s") || !strcmp(argv[1], "--system"))		output_system();
		else if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--hostname"))	output_hostname_only();
		else if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "--cpu"))		output_cpu_only();
		else if(!strcmp(argv[1], "--version"))								output_version();
		else if(!strcmp(argv[1], "--help"))									output_help();
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
