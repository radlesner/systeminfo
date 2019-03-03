/*
 * functions_output.h
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */

#ifndef FUNCTIONS_OUTPUT_H_
#define FUNCTIONS_OUTPUT_H_

#include <iostream>
#include <string>
#include <sys/utsname.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <time.h>
#include <ctime>

using namespace std;

	string program_version();
	void output_compile_information();
	void separator(string name);
	void output_main_information();
	void output_system();
	void output_network();
	void output_cpu_only();
	void output_help();
	void output_check_files();
	void output_monitor(int value_argc, char** value_argv);
	void output_log();

#endif /* FUNCTIONS_OUTPUT_H_ */