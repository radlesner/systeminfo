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

		if( (mem_used < 1) && (switch_megabyte == 1) ) mem_megabyte_file();
		else
		{
			cout.precision(3);
			cout << "RAM  Total/Available/Used : " << mem_max << "/" << mem_available << "/" << mem_used << " GB" << endl;
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
			cout << "RAM  Total/Free           : " << mem_max << "/" << mem_free << " GB" << endl;
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

		cout << "RAM  Total/Available/Used : " << mem_max << "/" << mem_available << "/" << mem_used << " MB" << endl;
	}
	else
	{
		string value_1 = open_file(input_value, line_1);
		string value_2 = open_file(input_value, line_2);

		mem_max		= atoi(value_1.c_str()) / 1024;
		mem_free	= atoi(value_2.c_str()) / 1024;

		cout << "RAM  Total/Free           : " << mem_max << "/" << mem_free << " MB" << endl;
	}
}

void disk_usage(int swith_units)
{
	ifstream disk_name;
	ifstream disk_used;
	ifstream disk_procent_usage;
	ifstream disk_available;
	ifstream disk_mount;

	string table_disk_name[512];
	string table_disk_used[512];
	string table_procent_usage[512];
	string table_disk_available[512];
	string table_disk_mount[512];
	string output[4];

	int nr_line = 1;
	int count = 0;

	disk_name.open(home_path() + "/.systeminfo-files/systeminfo-disks-name.txt");
	if (disk_name.good() == true)
	{
		while(!disk_name.eof())
		{
			getline(disk_name, table_disk_name[nr_line]);
			nr_line++;
		}
	}

	disk_procent_usage.open(home_path() + "/.systeminfo-files/systeminfo-disks-procent-usage.txt");
	if (disk_procent_usage.good() == true)
	{
		nr_line = 1;
		while(!disk_procent_usage.eof())
		{
			getline(disk_procent_usage, table_procent_usage[nr_line]);
			nr_line++;
		}
	}

	disk_used.open(home_path() + "/.systeminfo-files/systeminfo-disks-used.txt");
	if (disk_used.good() == true)
	{
		nr_line = 1;
		while(!disk_used.eof())
		{
			getline(disk_used, table_disk_used[nr_line]);
			nr_line++;
		}
	}

	disk_available.open(home_path() + "/.systeminfo-files/systeminfo-disks-avail.txt");
	if (disk_available.good() == true)
	{
		nr_line = 1;
		while(!disk_available.eof())
		{
			getline(disk_available, table_disk_available[nr_line]);
			nr_line++;
		}
	}

	disk_mount.open(home_path() + "/.systeminfo-files/systeminfo-disks-mount.txt");
	if (disk_mount.good() == true)
	{
		nr_line = 1;
		while(!disk_mount.eof())
		{
			getline(disk_mount, table_disk_mount[nr_line]);
			nr_line++;
		}
	}

	for (int i = 1; i < nr_line - 1; i++)
	{
		output[0]= "Usage       " + table_disk_name[i];
		output[1]= "Used        " + table_disk_name[i];
		output[2]= "Available   " + table_disk_name[i];
		output[3]= "Mount point " + table_disk_name[i];

		count = 26 - output[0].length();
		for (int x = 0; x < count; x++)
		{
			output[0] = output[0] + " ";
		}

		count = 26 - output[1].length();
		for (int x = 0; x < count; x++)
		{
			output[1] = output[1] + " ";
		}

		count = 26 - output[2].length();
		for (int x = 0; x < count; x++)
		{
			output[2] = output[2] + " ";
		}

		count = 26 - output[3].length();
		for (int x = 0; x < count; x++)
		{
			output[3] = output[3] + " ";
		}

		cout << output[0] << ": " << table_procent_usage[i] << endl;
		if (swith_units == 1)
		{
			cout.precision(3);
			cout << output[1] << ": " << static_cast<float>( atoi(table_disk_used[i].c_str()) ) / 1024 << " GB" << endl;
			cout << output[2] << ": " << static_cast<float>( atoi(table_disk_available[i].c_str()) ) / 1024 << " GB" << endl;
		}
		else
		{
			cout << output[1] << ": " << table_disk_used[i] << " MB" << endl;
			cout << output[2] << ": " << table_disk_available[i] << " MB" << endl;
		}
		cout << output[3] << ": " << table_disk_mount[i] << endl;
		separator("");
	}
}