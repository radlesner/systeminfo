/*
 * functions_output_swap.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: krupier
 */
#include "functions_file_swap.h"
#include "functions_file_operations.h"
#include "functions_file.h"
#include "functions_strings_operations.h"

using namespace std;

void swap_file(int switch_megabyte)
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-swap.txt";
	const int line_1 = 1;
	const int line_2 = 2;
	double swap_total, swap_free, swap_used;

	string value_1 = open_file(input_value, line_1);
	string value_2 = open_file(input_value, line_2);

	swap_total	= static_cast<double>( atoi(value_1.c_str()) )	/ 1024 / 1000;
	swap_free	= static_cast<double>( atoi(value_2.c_str()) )	/ 1024 / 1000;
	swap_used	= swap_total - swap_free;

	if( (swap_used < 1) && (switch_megabyte == 1) ) swap_megabyte_file();
	else
	{
		cout.precision(3);
		cout << bold() << "Swap Total/Used/Free" << bold_end() << ": " << swap_total << "/" << swap_used << "/" << swap_free << " GB" << endl;
	}
}

void swap_megabyte_file()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-swap.txt";
	const int line_1 = 1;
	const int line_2 = 2;
	int swap_total, swap_free, swap_used;

	string value_1 = open_file(input_value, line_1);
	string value_2 = open_file(input_value, line_2);

	swap_total	= atoi(value_1.c_str()) / 1024;
	swap_free	= atoi(value_2.c_str()) / 1024;
	swap_used	= swap_total - swap_free;

	cout << bold() << "Swap Total/Used/Free" << bold_end() << ": " << swap_total << "/" << swap_used << "/" << swap_free << " MB" << endl;
}