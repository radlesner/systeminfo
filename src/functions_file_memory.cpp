/*
 * functions_file_memory.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: krupier
 */
#include "functions_file_memory.h"
#include "function_open_file.h"

using namespace std;

void mem_file() {
	const string input_value = "/systeminfo-files/systeminfo-mem.txt";
	const int line_1 = 1;
	const int line_2 = 2;
	double mem_max, mem_free;

	string value_1 = open_file(input_value, line_1);
	string value_2 = open_file(input_value, line_2);

	mem_max		= (double)atoi(value_1.c_str()) / 1024 / 1000;
	mem_free	= (double)atoi(value_2.c_str()) / 1024 / 1000;

	cout << "RAM Total/Free:			" << mem_max << "/" << mem_free << " GB" << endl;
}

void mem_megabyte_file() {
	const string input_value = "/systeminfo-files/systeminfo-mem.txt";
	const int line_1 = 1;
	const int line_2 = 2;
	int mem_max, mem_free;

	string value_1 = open_file(input_value, line_1);
	string value_2 = open_file(input_value, line_2);

	mem_max		= atoi(value_1.c_str()) / 1024;
	mem_free	= atoi(value_2.c_str()) / 1024;

	cout << "RAM Total/Free:			" << mem_max << "/" << mem_free << " MB" << endl;
}
