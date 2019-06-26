/*
 * functions_output.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include "functions_output.h"
#include "functions_file.h"
#include "functions_file_operations.h"
#include "functions_file_memory.h"
#include "functions_file_swap.h"
#include "functions_command.h"
#include "functions_network.h"
#include "functions_strings_operations.h"

using namespace std;

string program_version()
{
	return "2.9.2";
}

void output_compile_information()
{
	cout << "Version program...........: " << program_version() << endl;
	cout << "Compile date..............: " << __DATE__ << endl;
	cout << "Compile time..............: " << __TIME__ << endl;
}

void separator(string name)
{
	string separator_1 = "────────────";
	string total;

	total = separator_1 + name;

	int count = 77 - total.length();
	for(int i = 0; i < count; i++)
	{
		total = total + "─";
	}

	cout << total << ">>>" << endl;
}

void output_main_information()
{
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0)
		{
			perror("uname");
			exit(EXIT_FAILURE);
		}

	separator("");
	cout << bold() << "Model name" << bold_end() << ": " << motherboard_manufacturer() << " " << model() << endl;
	cout << bold() << "Distribution" << bold_end() << ": " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
	cout << bold() << "Kernel version" << bold_end() << ": " << buffer.release << endl;
	cout << bold() << "System architecture" << bold_end() << ": " << architecture() << endl;
	cout << bold() << "CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
	cout << bold() << "Uptime" << bold_end() << ": " << uptime_file() << endl;

	separator("");
	mem_file(1);
	swap_file(1);

	separator("");
	get_ip_address(0);
}

void output_system()
{
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0)
		{
			perror("uname");
			exit(EXIT_FAILURE);
		}
	separator("");
	cout << bold() << "Model name" << bold_end() << ": " << model() << endl;
	cout << bold() << "Motherboard name" << bold_end() << ": " << motherboard() << endl;
	cout << bold() << "Motherboard manufacturer" << bold_end() << ": " << motherboard_manufacturer() << endl;
	cout << bold() << "BIOS manufacturer" << bold_end() << ": " << bios_manufacturer() << endl;
	cout << bold() << "BIOS version" << bold_end() << ": " << bios_version() << endl;
	cout << bold() << "BIOS date" << bold_end() << ": " << bios_date() << endl;
	separator("");
	cout << bold() << "OS Name" << bold_end() << ": " << buffer.sysname << endl;
	cout << bold() << "Distribution" << bold_end() << ": " << distribution_file() << endl;
	cout << bold() << "Release" << bold_end() << ": " << release_system() << endl;
	cout << bold() << "Kernel version" << bold_end() << ": " << buffer.release << endl;
	cout << bold() << "System architecture" << bold_end() << ": " << architecture() << endl;
	cout << bold() << "Shell" << bold_end() << ": " << shell_file() << endl;
	separator("");
	cout << bold() << "CPU" << bold_end() << ": " << cpu_file() << endl;
	cout << bold() << "Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
	cout << bold() << "CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
	separator("");
}

void output_network()
{
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0)
		{
			perror("uname");
			exit(EXIT_FAILURE);
		}

	separator("");
	cout << bold() << "Hostname" << bold_end() << ": " << buffer.nodename << endl;
	cout << bold() << "Logged user" << bold_end() << ": " << user_file() << endl;

	separator("");
	all_network();
}

void output_cpu_only()
{
	separator("");
	cout << bold() << "CPU" << bold_end() << ": " << cpu_file() << endl;
	cout << bold() << "Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
	cout << bold() << "Fan speed" << bold_end() << ": " << fan_speed() << endl;

	separator("");
	cout << bold() << "CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
	cout << bold() << "Max Frequency" << bold_end() << ": " << cpu_freq_max() << " MHz" << endl;
	cout << bold() << "Min Frequency" << bold_end() << ": " << cpu_freq_min() << " MHz" << endl;
	separator("");
	temperatures();
}

void output_check_files()
{
	ifstream mem_file("/home/"+user_file()+"/.systeminfo-files");	// systeminfo-files is a directory
	if(mem_file.good() == false)
	{
		command_check_folder_exist();
	}
	else
	{
		cout << "All files and folders is integrated ✔" << endl;
	}
}

void output_monitor(int value_argc, char** value_argv)
{
	int count = 0;
	string table[3];
	table[0] = "/";
	table[1] = "-";
	table[2] = "\\";

	for(;;) {
		command_activate();

		if(value_argc > 2) {
			if(!strcmp(value_argv[2], "-g"))
			{
				system("clear");

				separator("");
				cout << bold() << "CPU" << bold_end() << ": " << cpu_file() << endl;
				cout << bold() << "Theards" << bold_end() << ": " << theards_file() << endl;
				cout << bold() << "CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;

				separator("");
				cout << bold() << "Uptime" << bold_end() << ": " << uptime_file() << endl;

				separator("");
				mem_file(0);
				swap_file(0);
				separator("");

				all_network();
			}
			else if(!strcmp(value_argv[2], "-m"))
			{
				system("clear");

				separator("");
				cout << bold() << "CPU" << bold_end() << ": " << cpu_file() << endl;
				cout << bold() << "Theards" << bold_end() << ": " << theards_file() << endl;
				cout << bold() << "CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;

				separator("");
				cout << bold() << "Uptime" << bold_end() << ": " << uptime_file() << endl;

				separator("");
				mem_megabyte_file();
				swap_megabyte_file();
				separator("");

				all_network();
			}
			else if(!strcmp(value_argv[2], "-c"))
			{
				system("clear");

				separator("");
				cout << bold() << "CPU" << bold_end() << ": " << cpu_file() << endl;
				cout << bold() << "Cores/theards" << bold_end() << ": " << cores_file() << "/" << theards_file() << endl;
				cout << bold() << "Fan speed" << bold_end() << ": " << fan_speed() << endl;

				separator("");
				cout << bold() << "CPU Frequency" << bold_end() << ": " << cpu_frequency() << " MHz" << endl;
				cout << bold() << "Max Frequency" << bold_end() << ": " << cpu_freq_max() << " MHz" << endl;
				cout << bold() << "Min Frequency" << bold_end() << ": " << cpu_freq_min() << " MHz" << endl;
				separator("");
				temperatures();
			}
			else if(!strcmp(value_argv[2], "-n"))
			{
				system("clear");
				separator("");
				all_network();
			}
			else
			{
				cout << "Bad arguments, you must use operators: -t -m" << endl;
				cout << "                                       -t -g" << endl;
				cout << "                                       -t -n" << endl;
				cout << "                                       -t -c" << endl;
				cout << "Use --help operator to display help" << endl;
				break;
			}
		}
		else
		{
			cout << "Bad arguments, you must use operators: -t -m" << endl;
			cout << "                                       -t -g" << endl;
			cout << "                                       -t -n" << endl;
			cout << "                                       -t -c" << endl;
			cout << "Use --help operator to display help" << endl;
			break;
		}

		command_remove();
		cout << endl << "Exit: CTRL + C ";

		for (int i = 0; i < 1; i++)
		{
			cout << table[count] << endl;
			count++;

			if (count == 3)	count = 0;
		}

		sleep(1);
	}
}

void output_help()
{
	cout << "Usage: system [optional_option]" << endl;
	cout << "Options:" << endl;
	cout << "   -g  --gigabyte        Memory information in gigabyte form" << endl;
	cout << "   -m  --megabyte        Memory information in megabyte form" << endl;
	cout << "   -s  --system          System and hardware information" << endl;
	cout << "   -c  --cpu             CPU information" << endl;
	cout << "   -t  --monitor         real-time monitoring" << endl;
	cout << "       --log             Generating logs" << endl;
	cout << "       --check-files     Check integration files" << endl;
	cout << "       --help            Help panel" << endl;
	cout << "       --version         Version program and compilation" << endl;
	cout << "                         information" << endl << endl;

	cout << ">>> Example use command: systeminfo -s" << endl;
	cout << "                         systeminfo -t -m" << endl;
}