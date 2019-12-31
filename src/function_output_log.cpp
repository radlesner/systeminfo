#include "functions_output.h"
#include "functions_file.h"
#include "functions_file_operations.h"
#include "functions_file_memory.h"
#include "functions_file_swap.h"
#include "functions_command.h"
#include "functions_network.h"

using namespace std;

void output_log()
{
	cout << "Generating log            : ";

	fstream check_folder(home_path() + "/.systeminfo-files/logs/", ios::in); //---------------/ is a directory /---------------
	if(check_folder.good() == false)
		system("cd $HOME/.systeminfo-files/ && mkdir logs/");

 	clock_t countdown = clock();

	string path_filename = home_path() + "/.systeminfo-files/logs/";
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

	string bits = open_file(home_path()+"/.systeminfo-files/systeminfo-arch.txt", 1);
	string theards = open_file(home_path()+"/.systeminfo-files/systeminfo-cores.txt", 1);
	string shell = open_file(home_path()+"/.systeminfo-files/systeminfo-shell.txt", 1);

	struct utsname buffer;

		if (uname(&buffer) != 0)
		{
			perror("uname");
			exit(EXIT_FAILURE);
		}

	fstream log_file;
	log_file.open(file_name_fstream.c_str(), ios::out);

	log_file << "Log generated..............: " << in_file_time << endl;
	log_file << "Program name...............: systeminfo" << endl;
	log_file << "Program version............: " << program_version() << endl;
	log_file << "Compile program date.......: " << __DATE__ << ", " << __TIME__ << endl << endl;

	log_file << "------------- HARDWARE INFORMATION -------------" << endl;
	log_file << "Model name                 : " << model() << endl;
	log_file << "Motherboard name           : " << motherboard() << endl;
	log_file << "Motherboard manufacturer   : " << motherboard_manufacturer() << endl;
	log_file << "BIOS manufacturer          : " << bios_manufacturer() << endl;
	log_file << "BIOS version               : " << bios_version() << endl;
	log_file << "BIOS date                  : " << bios_date() << endl << endl;

	log_file << "-------------- SYSTEM INFORMATION --------------" << endl;
	log_file << "OS name                    : " << buffer.sysname << endl;
	log_file << "Distribution               : " << distribution_file() << endl;
	log_file << "Release                    : " << release_system() << endl;
	log_file << "Kernel                     : " << buffer.release << endl;
	log_file << "System architecture        : " << architecture() << endl;
	log_file << "Bits                       : " << bits << endl;
	log_file << "Shell                      : " << shell_file() << endl;
	log_file << "Uptime                     : " << uptime_file() << endl << endl;

	log_file << "---------------------- CPU ---------------------" << endl;
	log_file << "CPU                        : " << cpu_file() << endl;
	log_file << "Cores                      : " << cores_file() << endl;
	log_file << "Theards                    : " << theards_file() << endl;
	log_file << "CPU Frequency              : " << cpu_frequency() << " MHz" << endl;
	log_file << "Max Frequency              : " << cpu_freq_max() << " MHz" << endl;
	log_file << "Min Frequency              : " << cpu_freq_min() << " MHz" << endl << endl;

	log_file << "------------------- NETWORK --------------------" << endl;
	log_file << "Hostname                   : " << buffer.nodename << endl;

	/*
		NETWORK ---------------------------------------------------------------------------------------------------------->
        GATEWAY
    */
   {
		ifstream file;
		int nr = 0;
		string interfaces[32];
		string addresses[32];
		string text;
		string final_output;
		file.open(home_path()+"/.systeminfo-files/systeminfo-gateway-names.txt");
		if (file.good() == true)
		{
			while(!file.eof())
			{
				getline(file, text);
				nr++;
			}
		}
		file.close();
		/*
			GATEWAY END
			ADDRESS AND NETMASK
		*/
		struct ifaddrs* ifAddrStruct = NULL;
		struct ifaddrs* ifa = NULL;
		void* tmpAddrPtr = NULL;

		string netmask_output, address_output;

		getifaddrs(&ifAddrStruct);
		/*
			ADDRESS AND NETMASK END
			ADDRESS AND NETMASK OUTPUT
		*/
		for(ifa = ifAddrStruct;  ifa != NULL; ifa = ifa->ifa_next)
		{
			if (!ifa->ifa_addr) continue;
			if (ifa->ifa_addr->sa_family == AF_INET)
			{
				char address_buffer[INET_ADDRSTRLEN];
				char mask_buffer[INET_ADDRSTRLEN];

				tmpAddrPtr = &((struct sockaddr_in *)(ifa->ifa_addr))->sin_addr;
				inet_ntop(AF_INET, tmpAddrPtr, address_buffer, INET_ADDRSTRLEN);

				tmpAddrPtr = &((struct sockaddr_in *)(ifa->ifa_netmask))->sin_addr;
				inet_ntop(AF_INET, tmpAddrPtr, mask_buffer, INET_ADDRSTRLEN);

				address_output = "IPv4    (" + static_cast<string>(ifa->ifa_name) + ")";
				netmask_output = "Netmask (" + static_cast<string>(ifa->ifa_name) + ")";
				int count = 0;
				count = 27 - netmask_output.length();
				for(int i = 0; i < count; i++)
				{
					address_output = address_output + " ";
					netmask_output = netmask_output + " ";
				}
				/*
					OUTPUT
				*/

				log_file << address_output << ": " << address_buffer << endl;
				log_file << netmask_output << ": " << mask_buffer <<  endl;

				if (static_cast<string>(ifa->ifa_name) == "lo")
					log_file << endl;
				else
				{
					string ip_addr = get_gateway( static_cast<string>(ifa->ifa_name) );
					string gateway_output = "Gateway (" + static_cast<string>(ifa->ifa_name) + ")";

					count = 27 - gateway_output.length();
					for(int i = 0; i < count; i++)
					{
						gateway_output += " ";
					}

					log_file << gateway_output << ": " << ip_addr << endl << endl;
				}

				/*
					OUTPUT END
				*/
			}
		}
		if (ifAddrStruct != NULL) freeifaddrs(ifAddrStruct);
	}
	/*
		NETWORK END ------------------------------------------------------------------------------------------------------>
    */

	int time_gen = clock() - countdown;
	log_file << "Log generation time........: " << time_gen << " ms" << endl;

	cout << "Done" << endl;
	cout << "Generated date            : " << in_file_time << endl;
	cout << "Logs localization         : " << home_path() << "/.systeminfo-files/logs" << endl;
	cout << "Name file                 : " << file_name << endl;
	cout << "Log generation time       : " << time_gen << " ms" << endl;
}