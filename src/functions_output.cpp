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

using namespace std;

string program_version() {
	return "2.3";
}

void output_compile_information() {
	cout << "Version program...........: " << program_version() << endl;
	cout << "Compile date..............: " << __DATE__ << endl;
	cout << "Compile time..............: " << __TIME__ << endl;
}

void separator(string name) {
	string separator_1 = "────────────";
	string total;

	total = separator_1 + name;

	int count = 77 - total.length();
	for(int i = 0; i < count; i++) {
		total = total + "─";
	}


	cout << total << ">>>" << endl;
}

void output_main_information() {
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	separator("");
	cout << "Model name                : " << model() << endl;
	cout << "Distribution              : " << distribution_file() << " " << release_system() << " (" << cedename_system() << ")" << endl;
	cout << "Kernel version            : " << buffer.release << endl;
	architecture();
	cpu_frequency();
	cout << "Uptime                    : " << uptime_file() << endl;

	separator("");
	mem_file(1);
	swap_file(1);

	separator("");
	get_ip_address(0);
}

void output_system() {
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}
	separator("");
	cout << "Model name                : " << model() << endl;
	cout << "Motherboard name          : " << motherboard() << endl;
	cout << "Motherboard manufacturer  : " << motherboard_manufacturer() << endl;
	cout << "BIOS manufacturer         : " << bios_manufacturer() << endl;
	cout << "BIOS version              : " << bios_version() << endl;
	cout << "BIOS date                 : " << bios_date() << endl;
	separator("");
	cout << "OS Name                   : " << buffer.sysname << endl;
	cout << "Distribution              : " << distribution_file() << endl;
	cout << "Release                   : " << release_system() << endl;
	cout << "Kernel version            : " << buffer.release << endl;
	shell_file();

	separator("");
	architecture();
	cpu_file();
	cout << "Theards                   : " << theards_file() << endl;
	cpu_frequency();
	separator("");
}

void output_network() {
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	separator("");
	cout << "Hostname                  : " << buffer.nodename << endl;
	cout << "Logged user               : " << user_file() << endl;

	separator("");
	all_network();
}

void output_cpu_only() {
	separator("");
	cpu_file();
	cout << "Theards                   : " << theards_file() << endl;

	separator("");
	cpu_frequency();
	cpu_freq_max_min();
	separator("");
}

void output_check_files() {
	ifstream mem_file("/home/"+user_file()+"/.systeminfo-files");	// systeminfo-files is a directory
	if(mem_file.good() == false) {
		command_check_folder_exist();
	}
	else {
		cout << "All files and folders is integrated ✔" << endl;
	}
}

void output_monitor(int value_argc, char** value_argv) {
	int count = 0;
	string table[3];
	table[0] = "/";
	table[1] = "-";
	table[2] = "\\";

	for(;;) {
		command_activate();

		if(value_argc > 2) {
			if(!strcmp(value_argv[2], "-g")) {
				system("clear");

				separator("");
				cpu_file();
				cout << "Theards                   : " << theards_file() << endl;
				cpu_frequency();

				separator("");
				cout << "Uptime                    : " << uptime_file() << endl;

				separator("");
				mem_file(0);
				swap_file(0);
				separator("");

				all_network();
			}
			else if(!strcmp(value_argv[2], "-m")) {
				system("clear");

				separator("");
				cpu_file();
				cout << "Theards                   : " << theards_file() << endl;
				cpu_frequency();

				separator("");
				cout << "Uptime                    : " << uptime_file() << endl;

				separator("");
				mem_megabyte_file();
				swap_megabyte_file();
				separator("");

				all_network();
			}
			else if(!strcmp(value_argv[2], "-n")) {
				system("clear");
				separator("");
				all_network();
			}
			else {
				cout << "Bad arguments, you must use operators: -t -m" << endl;
				cout << "                                       -t -g" << endl;
				cout << "                                       -t -n" << endl;
				cout << "Use --help operator to display help" << endl;
				break;
			}
		}
		else {
			system("clear");

			separator("");
			cpu_file();
			cout << "Theards                   : " << theards_file() << endl;
			cpu_frequency();

			separator("");
			cout << "Uptime                    : " << uptime_file() << endl;

			separator("");
			mem_file(1);
			swap_file(1);
			separator("");

			all_network();
		}

		command_remove();
		cout << endl << "Exit: CTRL + C ";

		for (int i = 0; i < 1; i++)	{
			cout << table[count] << endl;
			count++;

			if (count == 3)	count = 0;
		}

		sleep(1);
	}
}

void output_help() {
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