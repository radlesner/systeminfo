/*
 * functions_file.h
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */

#ifndef FUNCTIONS_FILE_H_
#define FUNCTIONS_FILE_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/utsname.h>

using namespace std;

	string uptime_file();
	string distribution_file();
	string release_system();
	string cedename_system();
	void cpu_file();
	void architecture();
	void cpu_frequency();
	void cpu_freq_max_min();
	void cores_file();
	void shell_file();
	string user_file();
	string home_path();

#endif /* FUNCTIONS_FILE_H_ */