/*
 * functions_output.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include "functions_output.h"
#include "functions_output_memory_swap.h"
#include "functions_file.h"
#include "functions_file_operations.h"
#include "functions_file_memory.h"
#include "functions_file_swap.h"
#include "functions_command.h"

using namespace std;

string version;

void output_all() {
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "OS Name....................: " << buffer.sysname << endl;
	cout << "Distribution...............: " << distribution_file() << " " << release_system() << endl;
	cout << "Kernel version.............: " << buffer.release << endl;
	architecture();
	cpu_file();
	cores_file();
	output_memory();
	shell_file();
	cout << "Logged user................: " << user_file() << endl;
	cout << "Hostname...................: " << buffer.nodename << endl;
	cout << "Uptime.....................: " << uptime_file() << endl;
}

void output_system() {
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "OS Name....................: " << buffer.sysname << endl;
	cout << "Distribution...............: " << distribution_file() << endl;
	cout << "Release....................: " << release_system() << endl;
	cout << "Kernel version.............: " << buffer.release << endl;
	cout << "System architecture........: " << buffer.machine << endl;
	cpu_file();
	cores_file();
	cpu_frequency();
	shell_file();
}

void output_network() {
	string shell;
	shell = getenv ("SHELL");

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	cout << "Hostname...................: " << buffer.nodename << endl;
	cout << "Logged user................: " << user_file() << endl << endl;

	cout << "SSH Command................: " << user_file() << "@" << buffer.nodename << ".local" << endl;
}

void output_cpu_only() {
	cpu_file();
	cores_file();
	cpu_frequency();
	cout << "Max Frequency..............: " << cpu_frequency_max() << " MHz" << endl;
	cout << "Min Frequency..............: " << cpu_frequency_min() << " MHz" << endl;
}

void output_check_files() {
	ifstream mem_file("/systeminfo-files");							// systeminfo-files is a directory
	if(mem_file.good() == false) {
		command_check_folder_exist();
	}
	else {
		cout << "All files is integrated ✔" << endl;
	}
}

void output_monitor(int value_1, char** value_2) {
	for(;;) {
		command_activate();

		if(value_1 > 2) {
			system("clear");
			if(value_1 > 3)
				if(!strcmp(value_2[3], "-l") || !strcmp(value_2[3], "--logo"))	output_logo();
			if(!strcmp(value_2[2], "-m")) {
				cpu_file();
				cores_file();
				cpu_frequency();
				cout << "Uptime.....................: " << uptime_file() << endl << endl;
				output_memory();
			}
			else if(!strcmp(value_2[2], "-M")){
				cpu_file();
				cores_file();
				cpu_frequency();
				cout << "Uptime.....................: " << uptime_file() << endl << endl;
				output_memory_megabyte();
			}
			else {
				cout << "systeminfo: Too few arguments" << endl;
				cout << "Example: systeminfo -t -m" << endl;
				break;
			}
		}
		else {
			cout << "systeminfo: Too few arguments, minimum two" << endl;
			cout << "example: systeminfo -t -m" << endl;
			break;
		}

		command_remove();
		cout << endl << "Exit to: CTRL + C" << endl;
		sleep(1);
	}
}

void output_save_file() {
	string first_step = "systeminfo log ";
	time_t actual_time;
	time(&actual_time);

	string file_name = first_step + ctime(&actual_time);

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

	fstream file;

	file.open(file_name, ios::out);
	file << "         ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ " << endl;
	file << "        ||S |||Y |||S |||T |||E |||M |||I |||N |||F |||O ||" << endl;
	file << "        ||__|||__|||__|||__|||__|||__|||__|||__|||__|||__||" << endl;
	file << "        |/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|" << endl << endl;

	file << "Log generated: " << ctime(&actual_time);
	file << "Ptrogram name: systeminfo" << endl;
	file << "Program version: 0.8.2" << endl;

	file << endl;

	file << "------------------------|------------------------------------------------" << endl;
	file << "          NAME          |                       VALUE"						<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Os name                | " << buffer.sysname								<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Distribution           | " << distribution_file()							<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Release                | " << release_system()							<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Kernel                 | " << buffer.release								<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Architecture           | " << architecture								<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Bits                   | " << bits										<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Cpu                    | " << cpu											<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Theards                | " << theards										<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Shell                  | " << shell										<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Hostname               | " << buffer.nodename								<< endl;
	file << "------------------------|------------------------------------------------" << endl;
	file << " Uptime                 | " << uptime_file()								<< endl;
}

void output_help() {
	cout << "Usage: system [optional_option]" << endl;
	cout << "Options:" << endl;
	cout << "   -m  --memory            Memory information in gigabyte form" << endl;
	cout << "   -M  --memory-megabyte   Memory information in megabyte form" << endl;
	cout << "   -s  --system            System and hardware information" << endl;
	cout << "   -h  --ssh               SSH information" << endl;
	cout << "   -c  --cpu               CPU information" << endl;
	cout << "   -l  --logo              Show the logo" << endl;
	cout << "   -t  --monitor           real-time monitoring" << endl;
	cout << "       --log               Generating logs" << endl;
	cout << "       --check-files       Check integration files" << endl;
	cout << "       --help              Help panel" << endl;
	cout << "       --version           Version program and compilation" << endl;
	cout << "                           information" << endl;
	cout << "Example: systeminfo -s -l" << endl;
}

void output_logo() {
   cout << " ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ " << endl;
   cout << "||S |||Y |||S |||T |||E |||M |||I |||N |||F |||O ||" << endl;
   cout << "||__|||__|||__|||__|||__|||__|||__|||__|||__|||__||" << endl;
   cout << "|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|" << endl;

   cout << endl;
}