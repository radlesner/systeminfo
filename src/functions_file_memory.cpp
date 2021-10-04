/*
 * functions_file_memory.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: krupier
 */
#include "functions_file_memory.h"
#include "functions_file_operations.h"
#include "functions_file.h"
#include "functions_output.h"
#include "functions_strings_operations.h"

using namespace std;

int string_confirmed;

void mem_file(int switch_megabyte)
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-mem.txt";
	const int line_1 = 1;
	const int line_2 = 2;
	const int line_3 = 3;
	double mem_max, mem_free, mem_available, mem_used;

	const string search_file_input = "/proc/meminfo";
	const string search_file_text = "MemAvailable:";
	check_file_text(search_file_input, search_file_text);

	if(string_confirmed == 1)
	{
		string value_1 = open_file(input_value, line_1);
		string value_3 = open_file(input_value, line_3);

		mem_max			= static_cast<double>( atoi(value_1.c_str()) ) / 1024 / 1000;
		mem_available	= static_cast<double>( atoi(value_3.c_str()) ) / 1024 / 1000;
		mem_used = mem_max - mem_available;

		if( (mem_available < 1) && (switch_megabyte == 1) ) mem_megabyte_file();
		else
		{
			cout.precision(3);
			cout << bold() << "RAM  Total/Used/Free" << bold_end() << ": " << mem_max << "/" << mem_used << "/" << mem_available << " GB" << endl;
		}
	}
	else
	{
		string value_1 = open_file(input_value, line_1);
		string value_2 = open_file(input_value, line_2);

		mem_max		= static_cast<double>( atoi(value_1.c_str()) ) / 1024 / 1000;
		mem_free	= static_cast<double>( atoi(value_2.c_str()) ) / 1024 / 1000;

		if( (mem_max < 1) && (switch_megabyte == 1) ) mem_megabyte_file();
		else
		{
			cout.precision(3);
			cout << bold() << "RAM  Total/Free" << bold_end() << ": " << mem_max << "/" << mem_free << " GB" << endl;
		}
	}
}

void mem_megabyte_file()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-mem.txt";
	const int line_1 = 1;
	const int line_2 = 2;
	const int line_3 = 3;
	int mem_max, mem_free, mem_available, mem_used;

	const string search_file_input = "/proc/meminfo";
	const string search_file_text = "MemAvailable:";
	check_file_text(search_file_input, search_file_text);

	if(string_confirmed == 1)
	{
		string value_1 = open_file(input_value, line_1);
		string value_3 = open_file(input_value, line_3);

		mem_max			= static_cast<double>( atoi(value_1.c_str()) ) / 1024;
		mem_available	= static_cast<double>( atoi(value_3.c_str()) ) / 1024;
		mem_used = mem_max - mem_available;

		cout << bold() << "RAM  Total/Used/Free" << bold_end() << ": " << mem_max << "/" << mem_used << "/" << mem_available << " MB" << endl;
	}
	else
	{
		string value_1 = open_file(input_value, line_1);
		string value_2 = open_file(input_value, line_2);

		mem_max		= atoi(value_1.c_str()) / 1024;
		mem_free	= atoi(value_2.c_str()) / 1024;

		cout << bold() << "RAM  Total/Free" << bold_end() << ": " << mem_max << "/" << mem_free << " MB" << endl;
	}
}