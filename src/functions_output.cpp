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
	return "2.6";
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
	cout << bold_text_start() << "Model name                : " << bold_text_end() << motherboard_manufacturer() << " " << model() << endl;
	cout << bold_text_start() << "Distribution              : " << bold_text_end() << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
	cout << bold_text_start() << "Kernel version            : " << bold_text_end() << buffer.release << endl;
	cout << bold_text_start() << "System architecture       : " << bold_text_end() << architecture() << endl;
	cout << bold_text_start() << "CPU Frequency             : " << bold_text_end() << cpu_frequency() << " MHz" << endl;
	cout << bold_text_start() << "Uptime                    : " << bold_text_end() << uptime_file() << endl;

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
	cout << bold_text_start() << "Model name                : " << bold_text_end() << model() << endl;
	cout << bold_text_start() << "Motherboard name          : " << bold_text_end() << motherboard() << endl;
	cout << bold_text_start() << "Motherboard manufacturer  : " << bold_text_end() << motherboard_manufacturer() << endl;
	cout << bold_text_start() << "BIOS manufacturer         : " << bold_text_end() << bios_manufacturer() << endl;
	cout << bold_text_start() << "BIOS version              : " << bold_text_end() << bios_version() << endl;
	cout << bold_text_start() << "BIOS date                 : " << bold_text_end() << bios_date() << endl;
	separator("");
	cout << bold_text_start() << "OS Name                   : " << bold_text_end() << buffer.sysname << endl;
	cout << bold_text_start() << "Distribution              : " << bold_text_end() << distribution_file() << endl;
	cout << bold_text_start() << "Release                   : " << bold_text_end() << release_system() << endl;
	cout << bold_text_start() << "Kernel version            : " << bold_text_end() << buffer.release << endl;
	cout << bold_text_start() << "System architecture       : " << bold_text_end() << architecture() << endl;
	cout << bold_text_start() << "Shell                     : " << bold_text_end() << shell_file() << endl;
	separator("");
	cout << bold_text_start() << "CPU                       : " << bold_text_end() << cpu_file() << endl;
	cout << bold_text_start() << "Cores/theards             : " << bold_text_end() << cores_file() << "/" << theards_file() << endl;
	cout << bold_text_start() << "CPU Frequency             : " << bold_text_end() << cpu_frequency() << " MHz" << endl;
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
	cout << bold_text_start() << "Hostname                  : " << bold_text_end() << buffer.nodename << endl;
	cout << bold_text_start() << "Logged user               : " << bold_text_end() << user_file() << endl;

	separator("");
	all_network();
}

void output_cpu_only()
{
	separator("");
	cout << bold_text_start() << "CPU                       : " << bold_text_end() << cpu_file() << endl;
	cout << bold_text_start() << "Cores/theards             : " << bold_text_end() << cores_file() << "/" << theards_file() << endl;
	cout << bold_text_start() << "Fan speed                 : " << bold_text_end() << fan_speed() << endl;

	separator("");
	cout << bold_text_start() << "CPU Frequency             : " << bold_text_end() << cpu_frequency() << " MHz" << endl;
	cout << bold_text_start() << "Max Frequency             : " << bold_text_end() << cpu_freq_max() << " MHz" << endl;
	cout << bold_text_start() << "Min Frequency             : " << bold_text_end() << cpu_freq_min() << " MHz" << endl;
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
				cout << bold_text_start() << "CPU                       : " << bold_text_end() << cpu_file() << endl;
				cout << bold_text_start() << "Theards                   : " << bold_text_end() << theards_file() << endl;
				cout << bold_text_start() << "CPU Frequency             : " << bold_text_end() << cpu_frequency() << " MHz" << endl;

				separator("");
				cout << bold_text_start() << "Uptime                    : " << bold_text_end() << uptime_file() << endl;

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
				cout << bold_text_start() << "CPU                       : " << bold_text_end() << cpu_file() << endl;
				cout << bold_text_start() << "Theards                   : " << bold_text_end() << theards_file() << endl;
				cout << bold_text_start() << "CPU Frequency             : " << bold_text_end() << cpu_frequency() << " MHz" << endl;

				separator("");
				cout << bold_text_start() << "Uptime                    : " << bold_text_end() << uptime_file() << endl;

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
				cout << bold_text_start() << "CPU                       : " << bold_text_end() << cpu_file() << endl;
				cout << bold_text_start() << "Cores/theards             : " << bold_text_end() << cores_file() << "/" << theards_file() << endl;
				cout << bold_text_start() << "Fan speed                 : " << bold_text_end() << fan_speed() << endl;

				separator("");
				cout << bold_text_start() << "CPU Frequency             : " << bold_text_end() << cpu_frequency() << " MHz" << endl;
				cout << bold_text_start() << "Max Frequency             : " << bold_text_end() << cpu_freq_max() << " MHz" << endl;
				cout << bold_text_start() << "Min Frequency             : " << bold_text_end() << cpu_freq_min() << " MHz" << endl;
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