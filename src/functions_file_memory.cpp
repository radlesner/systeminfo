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

	double mem_max_conventer, mem_max, mem_available_conventer, mem_available, mem_used;
	string mem_max_string, mem_available_string;

	ifstream mem_file("/systeminfo-files/systeminfo-mem.txt");

	if(mem_file.good()==false)
		cout << "Error 006: Not found file \"systeminfo-mem.txt\"" << endl;

	while (getline(mem_file, mem_line)) {
		switch (mem_nr_line) {
			case 1: mem_max_string=mem_line; break;
			case 2: mem_available_string=mem_line; break;
		}
		mem_nr_line++;
	}

	mem_file.close();

	istringstream memmax(mem_max_string);
	memmax >> mem_max_conventer;

	mem_max = mem_max_conventer / 1024 / 1024;


	istringstream memavailable(mem_available_string);
	memavailable >> mem_available_conventer;

	mem_available = mem_available_conventer / 1024 / 1024;

	mem_used = mem_max - mem_available;

	cout << "RAM Total/Available/Used:	" << mem_max << " GB/" << mem_available << " GB/" << mem_used << " GB" << endl;
}

void mem_megabyte_file() {
	string mem_line;
	int mem_nr_line=1;

	double mem_max_conventer, mem_max, mem_available_conventer, mem_available, mem_used;
	string mem_max_string, mem_available_string;

	ifstream mem_file("/systeminfo-files/systeminfo-mem.txt");

	if(mem_file.good()==false)
		cout << "Error 006: Not found file \"systeminfo-mem.txt\"" << endl;

	while (getline(mem_file, mem_line)) {
		switch (mem_nr_line) {
			case 1: mem_max_string=mem_line; break;
			case 2: mem_available_string=mem_line; break;
		}
		mem_nr_line++;
	}

	mem_file.close();

	istringstream memmax(mem_max_string);
	memmax >> mem_max_conventer;

	mem_max = mem_max_conventer / 1024;


	istringstream memavailable(mem_available_string);
	memavailable >> mem_available_conventer;

	mem_available = mem_available_conventer / 1024;

	mem_used = mem_max - mem_available;

	cout << "RAM Total/Available/Used:	" << mem_max << " MB/" << mem_available << " MB/" << mem_used << " MB" << endl;
}

