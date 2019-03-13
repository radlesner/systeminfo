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
	return "1.7.4";
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
	cout << "OS Name                   : " << buffer.sysname << endl;
	cout << "Distribution              : " << distribution_file() << endl;
	cout << "Release                   : " << release_system() << endl;
	cout << "Kernel version            : " << buffer.release << endl;
	shell_file();

	separator("");
	architecture();
	cpu_file();
	cores_file();
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
	cores_file();

	separator("");
	cpu_frequency();
	cout << "Max Frequency             : " << cpu_frequency_max() << " MHz" << endl;
	cout << "Min Frequency             : " << cpu_frequency_min() << " MHz" << endl;
	separator("");
}

void output_check_files() {
	ifstream mem_file("/systeminfo-files");							// systeminfo-files is a directory
	if(mem_file.good() == false) {
		command_check_folder_exist();
	}
	else {
		cout << "All files and folders is integrated ✔" << endl;
	}
}

void output_monitor(int value_argc, char** value_argv) {
	for(;;) {
		command_activate();

		if(value_argc > 2) {
			if(!strcmp(value_argv[2], "-g")) {
				system("clear");

				separator("");
				cpu_file();
				cores_file();
				cpu_frequency();

				separator("");
				cout << "Uptime                    : " << uptime_file() << endl;

				separator("");
				mem_file(0);
				swap_file(0);
				separator("");
			}
			else if(!strcmp(value_argv[2], "-m")) {
				system("clear");

				separator("");
				cpu_file();
				cores_file();
				cpu_frequency();

				separator("");
				cout << "Uptime                    : " << uptime_file() << endl;

				separator("");
				mem_megabyte_file();
				swap_megabyte_file();
				separator("");
			}
			else {
				cout << "Bad arguments, you must use operators: ( -t -m ) or ( -t -g )" << endl;
				cout << "Use --help operator to display help" << endl;
				break;
			}
		}
		else {
			system("clear");

			separator("");
			cpu_file();
			cores_file();
			cpu_frequency();

			separator("");
			cout << "Uptime                    : " << uptime_file() << endl;

			separator("");
			mem_file(1);
			swap_file(1);
			separator("");
		}

		command_remove();
		cout << endl << "Exit to: CTRL + C" << endl;
		sleep(1);
	}
}

void output_log() {
	cout << "Generating log            : ";

	clock_t countdown = clock();

	string path_filename = "/systeminfo-files/logs/";
	string first_step = "systeminfo_log_";

	time_t system_time;
	struct tm* date;
	char filename_time[80], in_file_time[80];

	time(&system_time);
	date = localtime(&system_time);

	strftime(filename_time, 80, "%d_%b_%Y_%H_%M_%S", date);
	strftime(in_file_time, 80, "%d/%m/%Y, %H:%M:%S", date);

	string file_name_fstream = path_filename + first_step + filename_time;
	string file_name = first_step + filename_time;

	string architecture = open_file("/systeminfo-files/systeminfo-distro.txt", 3);
	string bits = open_file("/systeminfo-files/systeminfo-distro.txt", 4);
	string cpu = open_file("/systeminfo-files/systeminfo-cpu.txt", 1);
	string theards = open_file("/systeminfo-files/systeminfo-cores.txt", 1);
	string shell = open_file("/systeminfo-files/systeminfo-shell.txt", 1);

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	fstream log_file;
	log_file.open(file_name_fstream.c_str(), ios::out);

	log_file << "Log generated..............: " << in_file_time << endl;
	log_file << "Ptrogram name..............: systeminfo" << endl;
	log_file << "Program version............: " << program_version() << endl;
	log_file << "Compile program date.......: " << __DATE__ << ", " << __TIME__ << endl;
	log_file << "Log generation time........: " << clock() - countdown << " ms" << endl << endl;

	log_file << "          NAME          |                       VALUE"						<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Os name                | " << buffer.sysname								<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Distribution           | " << distribution_file()							<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Release                | " << release_system()							<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Kernel                 | " << buffer.release								<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Architecture           | " << architecture								<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Bits                   | " << bits										<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Cpu                    | " << cpu											<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Theards                | " << theards										<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Shell                  | " << shell										<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Hostname               | " << buffer.nodename								<< endl;
	log_file << "------------------------|------------------------------------------------" << endl;
	log_file << " Uptime                 | " << uptime_file()								<< endl;

	cout << "Done" << endl;
	cout << "Generated date            : " << in_file_time << endl;
	cout << "Logs localization         : /systeminfo-files/logs" << endl;
	cout << "Name file                 : " << file_name << endl;
	cout << "Log generation time       : " << clock() - countdown << " ms" << endl;
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