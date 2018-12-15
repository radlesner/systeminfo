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

using namespace std;

	void output_all();
	void output_system();
	void output_memory();
	void output_memory_megabyte();
	void output_hostname_only();
	void output_cpu_only();
	void output_help();
	void output_check_files();
	void output_logo();

#endif /* FUNCTIONS_OUTPUT_H_ */
