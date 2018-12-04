/*
 * functions_file_memory.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: krupier
 */
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
#include "functions_output_memory_swap.h"

using namespace std;

void mem_file() {
	string mem_line;
	int mem_nr_line=1;

	double mem_max_conventer, mem_max, mem_free_conventer, mem_free;
	string mem_max_string, mem_free_string;

	mem_max_string = "0";
	mem_free_string = "0";

	ifstream mem_file("/systeminfo-files/systeminfo-mem.txt");

	if(mem_file.good()==false)
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
	mem_max = mem_max_conventer / 1024 / 1000;

	istringstream memavailable(mem_free_string);
	memavailable >> mem_free_conventer;
	mem_free = mem_free_conventer / 1024 / 1000;

	cout << "RAM Total/Free:			" << mem_max << "/" << mem_free << "		GB" << endl;
}

void mem_megabyte_file() {
	string mem_line;
	int mem_nr_line=1;

	int mem_max_conventer, mem_max, mem_free_conventer, mem_free;
	string mem_max_string, mem_free_string;

	mem_max_string = "0";
	mem_free_string = "0";

	ifstream mem_file("/systeminfo-files/systeminfo-mem.txt");

	if(mem_file.good()==false)
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

	cout << "RAM Total/Free:			" << mem_max << "/" << mem_free << "	MB" << endl;
}
