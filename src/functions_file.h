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
	string cpu_file();
	string architecture();

	string model();
	string motherboard();
	string motherboard_manufacturer();
	string bios_manufacturer();
	string bios_version();
	string bios_date();

	int cpu_frequency();
	int cpu_freq_max();
	int cpu_freq_min();
	int theards_file();
	int cores_file();

	string shell_file();
	string user_file();
	string home_path();

	void temperatures();
	string fan_speed();

#endif /* FUNCTIONS_FILE_H_ */