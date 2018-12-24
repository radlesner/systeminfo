/*
 * functions_output_swap.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: krupier
 */
#include "functions_file_swap.h"
#include "functions_file_operations.h"

using namespace std;

void swap_file() {
	const string input_value = "/systeminfo-files/systeminfo-swap.txt";
	const int line_1 = 1;
	const int line_2 = 2;
	double swap_total, swap_free, swap_used;

	string value_1 = open_file(input_value, line_1);
	string value_2 = open_file(input_value, line_2);

	swap_total	= (double)atoi(value_1.c_str())	/ 1024 / 1000;
	swap_free	= (double)atoi(value_2.c_str())	/ 1024 / 1000;
	swap_used	= swap_total - swap_free;

	cout << "Swap Total/Free/Used:		" << swap_total << "/" << swap_free << "/" << swap_used << " GB" << endl;
}

void swap_megabyte_file() {
	const string input_value = "/systeminfo-files/systeminfo-swap.txt";
	const int line_1 = 1;
	const int line_2 = 2;
	int swap_total, swap_free, swap_used;

	string value_1 = open_file(input_value, line_1);
	string value_2 = open_file(input_value, line_2);

	swap_total	= atoi(value_1.c_str()) / 1024;
	swap_free	= atoi(value_2.c_str()) / 1024;
	swap_used	= swap_total - swap_free;


	cout << "Swap Total/Free/Used:		" << swap_total << "/" << swap_free << "/" << swap_used << " MB" << endl;
}
