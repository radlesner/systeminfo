/*
 * functions_output.h
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */

#ifndef FUNCTIONS_OUTPUT_H_
#define FUNCTIONS_OUTPUT_H_

#include <iostream>
#include <sys/utsname.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <time.h>
#include <ctime>

using namespace std;

	void output_all();
	void output_system();
	void output_network();
	void output_cpu_only();
	void output_help();
	void output_check_files();
	void output_logo();
	void output_monitor(int value_1, char** value_2);
	void output_save_file();

#endif /* FUNCTIONS_OUTPUT_H_ */