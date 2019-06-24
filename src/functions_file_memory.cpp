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

		if( (mem_used < 1) && (switch_megabyte == 1) ) mem_megabyte_file();
		else
		{
			cout.precision(3);
			cout << bold() << "RAM  Total/Free/Used" << bold_end() << ": " << mem_max << "/" << mem_available << "/" << mem_used << " GB" << endl;
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

		cout << bold() << "RAM  Total/Free/Used" << bold_end() << ": " << mem_max << "/" << mem_available << "/" << mem_used << " MB" << endl;
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

void disk_usage(int swith_units)
{
	ifstream disk_name;
	ifstream disk_size;
	ifstream disk_used;
	ifstream disk_procent_usage;
	ifstream disk_available;
	ifstream disk_mount;

	string table_disk_name[512];
	string table_disk_size[512];
	string table_disk_used[512];
	string table_procent_usage[512];
	string table_disk_available[512];
	string table_disk_mount[512];

	int nr_line = 1;
	int count = 0;

	float size[512];
	float used[512];
	float avail[512];

	disk_name.open(home_path() + "/.systeminfo-files/systeminfo-disks-name.txt");
	if (disk_name.good() == true)
	{
		while(!disk_name.eof())
		{
			getline(disk_name, table_disk_name[nr_line]);
			nr_line++;
		}
	}

	disk_size.open(home_path() + "/.systeminfo-files/systeminfo-disks-size.txt");
	if (disk_size.good() == true)
	{
		nr_line = 1;
		while(!disk_size.eof())
		{
			getline(disk_size, table_disk_size[nr_line]);
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
		size[i] = atoi( table_disk_size[i].c_str() );
		used[i] = atoi( table_disk_used[i].c_str() );
		avail[i] = size[i] - used[i];

		cout << bold() << "Disk        " << bold_end() << ": " << table_disk_name[i] << endl;
		cout << bold() << "Usage       " << bold_end() << ": " << table_procent_usage[i] << endl;
		if (swith_units == 1)
		{
			if (size[i] / 1024 < 1)
			{
				cout << bold() << "Size        " << bold_end() << ": " << size[i] << " MB" << endl;
				cout << bold() << "Used        " << bold_end() << ": " << used[i] << " MB" << endl;
				cout << bold() << "Available   " << bold_end() << ": " << avail[i] << " MB" << endl;
			}
			else
			{
				cout.precision(3);
				cout << bold() << "Size        " << bold_end() << ": " << size[i] / 1024 << " GB" << endl;
				cout << bold() << "Used        " << bold_end() << ": " << used[i] / 1024 << " GB" << endl;
				cout << bold() << "Available   " << bold_end() << ": " << avail[i] / 1024 << " GB" << endl;
			}
		}
		else
		{
			cout << bold() << "Size        " << bold_end() << ": " << size[i] << " MB" << endl;
			cout << bold() << "Used        " << bold_end() << ": " << used[i] << " MB" << endl;
			cout << bold() << "Available   " << bold_end() << ": " << avail[i] << " MB" << endl;
		}
		cout << bold() << "Mount point " << bold_end() << ": " << table_disk_mount[i] << endl;
		separator("");
	}
}