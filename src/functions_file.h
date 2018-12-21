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

using namespace std;

	string uptime_file();
	string distribution_file();
	void cpu_file();
	int cpu_frequency();
	int cpu_frequency_max();
	int cpu_frequency_min();
	void cores_file();
	void shell_file();
	string user_file();

#endif /* FUNCTIONS_FILE_H_ */
