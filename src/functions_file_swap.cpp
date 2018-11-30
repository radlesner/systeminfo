/*
 * functions_output_swap.cpp
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
#include "functions_file_memory.h"
#include "functions_file_swap.h"
#include "functions_file_swap.h"

#include "functions_output_memory_swap.h"

using namespace std;

void swap_file() {
	string swap_line;
	int swap_nr_line=1;

	double swap_total_conventer, swap_total, swap_free_conventer, swap_free, swap_usage;
	string swap_total_string, swap_free_string;

	ifstream swap_file("/systeminfo-files/systeminfo-swap.txt");

	if(swap_file.good()==false)
		cout << "Error 007: Not found file \"systeminfo-swap.txt\"" << endl;

	while (getline(swap_file, swap_line)) {
		switch (swap_nr_line) {
			case 1: swap_total_string=swap_line; break;
			case 2: swap_free_string=swap_line; break;
		}
		swap_nr_line++;
	}

	swap_file.close();

	istringstream swaptotal(swap_total_string);
	swaptotal >> swap_total_conventer;
	swap_total = swap_total_conventer / 1024 / 1024;

	istringstream swapfree(swap_free_string);
	swapfree >> swap_free_conventer;
	swap_free = swap_free_conventer / 1024 / 1024;

	swap_usage = swap_total - swap_free;

	cout << "Swap Total/Free/Usage:		" << swap_total << "/" << swap_free << "/" << swap_usage << "	GB" << endl;
}

void swap_megabyte_file() {
	string swap_line;
	int swap_nr_line=1;

	int swap_total_conventer, swap_total, swap_free_conventer, swap_free, swap_usage;
	string swap_total_string, swap_free_string;

	ifstream swap_file("/systeminfo-files/systeminfo-swap.txt");

	if(swap_file.good()==false)
		cout << "Error 007: Not found file \"systeminfo-swap.txt\"" << endl;

	while (getline(swap_file, swap_line)) {
		switch (swap_nr_line) {
			case 1: swap_total_string=swap_line; break;
			case 2: swap_free_string=swap_line; break;
		}
		swap_nr_line++;
	}

	swap_file.close();

	istringstream swaptotal(swap_total_string);
	swaptotal >> swap_total_conventer;
	swap_total = swap_total_conventer / 1024;

	istringstream swapfree(swap_free_string);
	swapfree >> swap_free_conventer;
	swap_free = swap_free_conventer / 1024;

	swap_usage = swap_total - swap_free;

	cout << "Swap Total/Free/Usage:		" << swap_total << "/" << swap_free << "/" << swap_usage << "	MB" << endl;
}
