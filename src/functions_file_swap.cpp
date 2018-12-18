/*
 * functions_output_swap.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: krupier
 */
#include "functions_file_swap.h"

using namespace std;

void swap_file() {
	string swap_line;
	int swap_nr_line = 1;

	double swap_total_conventer, swap_total, swap_free_conventer, swap_free;
	string swap_total_string, swap_free_string;

	swap_total_string = "0";
	swap_free_string = "0";

	ifstream swap_file("/systeminfo-files/systeminfo-swap.txt");

	if(swap_file.good() == false)
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
	swap_total = swap_total_conventer / 1024 / 1000;

	istringstream swapfree(swap_free_string);
	swapfree >> swap_free_conventer;
	swap_free = swap_free_conventer / 1024 / 1000;

	cout << "Swap Total/Free:		" << swap_total << "/" << swap_free << " GB" << endl;
}

void swap_megabyte_file() {
	string swap_line;
	int swap_nr_line = 1;

	int swap_total_conventer, swap_total, swap_free_conventer, swap_free;
	string swap_total_string, swap_free_string;

	swap_total_string = "0";
	swap_free_string = "0";

	ifstream swap_file("/systeminfo-files/systeminfo-swap.txt");

	if(swap_file.good() == false)
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

	cout << "Swap Total/Free:		" << swap_total << "/" << swap_free << " MB" << endl;
}
