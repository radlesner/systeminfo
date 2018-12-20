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

	mem_max = atoi(value_1.c_str());
	mem_free = atoi(value_2.c_str());

	mem_max = (double)mem_max / 1024 / 1000;
	mem_free = (double)mem_free / 1024 / 1000;

	cout << "RAM Total/Free:			" << mem_max << "/" << mem_free << " GB" << endl;
}

void mem_megabyte_file() {
	string mem_line;
	int mem_nr_line = 1;

	int mem_max_conventer, mem_max, mem_free_conventer, mem_free;
	string mem_max_string, mem_free_string;

	mem_max_string = "0";
	mem_free_string = "0";

	ifstream mem_file("/systeminfo-files/systeminfo-mem.txt");

	if(mem_file.good() == false)
		cout << "Error 006: Not found file \"systeminfo-mem.txt\"" << endl;

	while (getline(mem_file, mem_line)) {
		switch (mem_nr_line) {
			case 1: mem_max_string=mem_line; break;
			case 2: mem_free_string=mem_line; break;
		}
		mem_nr_line++;
	}

	mem_file.close();

	istringstream memmax(mem_max_string);
	memmax >> mem_max_conventer;
	mem_max = mem_max_conventer / 1024;

	istringstream memavailable(mem_free_string);
	memavailable >> mem_free_conventer;
	mem_free = mem_free_conventer / 1024;

	cout << "RAM Total/Free:			" << mem_max << "/" << mem_free << " MB" << endl;
}
