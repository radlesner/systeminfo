#include "functions_output.h"
#include "functions_file.h"
#include "functions_file_operations.h"
#include "functions_file_memory.h"
#include "functions_file_swap.h"
#include "functions_command.h"
#include "functions_network.h"

using namespace std;

void output_log() {
	cout << "Generating log            : ";

	ifstream check_folder(home_path() + "/.systeminfo-files/logs/"); //---------------/ is a directory /---------------
	if(check_folder.good() == false) system("cd $HOME/.systeminfo-files/ && mkdir logs/");

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

	string architecture = open_file(home_path()+"/.systeminfo-files/systeminfo-distro.txt", 3);
	string bits = open_file(home_path()+"/.systeminfo-files/systeminfo-arch.txt", 1);
	string cpu = open_file(home_path()+"/.systeminfo-files/systeminfo-cpu.txt", 1);
	string theards = open_file(home_path()+"/.systeminfo-files/systeminfo-cores.txt", 1);
	string shell = open_file(home_path()+"/.systeminfo-files/systeminfo-shell.txt", 1);

	struct utsname buffer;

		if (uname(&buffer) != 0) {
			perror("uname");
			exit(EXIT_FAILURE);
		}

	fstream log_file;
	log_file.open(file_name_fstream.c_str(), ios::out);

	log_file << "Log generated..............: " << in_file_time << endl;
	log_file << "Program name...............: systeminfo" << endl;
	log_file << "Program version............: " << program_version() << endl;
	log_file << "Compile program date.......: " << __DATE__ << ", " << __TIME__ << endl << endl;

	log_file << "-------------- SYSTEM INFORMATION --------------" << endl;
	log_file << "OS name                    : " << buffer.sysname << endl;
	log_file << "Distribution               : " << distribution_file() << endl;
	log_file << "Release                    : " << release_system() << endl;
	log_file << "Kernel                     : " << buffer.release << endl;
	log_file << "Architecture               : " << architecture << endl;
	log_file << "Bits                       : " << bits << endl;
	log_file << "Shell                      : " << shell << endl;
	log_file << "Uptime                     : " << uptime_file() << endl << endl;

	log_file << "---------------------- CPU ---------------------" << endl;
	log_file << "Cpu                        : " << cpu << endl;
	log_file << "Theards                    : " << theards << endl;
	/*
		FREQUENCY -------------------------------------------------------------------------------------------------------->
	*/
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-cpu-status.txt";

	int cores = theards_file();
	int frequency_sum = 0;
	int line = 1;

	string read_value;
	int value[512];

	fstream file;

    file.open(input_value, ios::in);
		if(file.good() == true) {
			for(int x = 0; x < cores; x++) {
				getline(file, read_value);
				if(read_value == "N/A") break;
				value[x++] = atoi(read_value.c_str());

				frequency_sum = frequency_sum + value[x];
			}
            for(int i = 0; i < cores; i++) {
                frequency_sum = frequency_sum + value[i];
            }

            frequency_sum = frequency_sum / cores / 1000;

            if(distribution_file() == "Raspbian" || read_value == "N/A")
                log_file << "CPU Frequency             : N/A" << endl;
            else
                log_file << "CPU Frequency             : " << frequency_sum << " MHz" << endl;
		}
		else {
			log_file << "CPU Frequency             : N/A" << endl;
		}
	file.close();

	if(open_file(home_path() + "/.systeminfo-files/systeminfo-cpu-frequency_max.txt", 1) == "N/A") {
		log_file << "Max Frequency             : N/A" << endl;
		log_file << "Min Frequency             : N/A" << endl;
		return;
	}

	int freq_max = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-cpu-frequency_max.txt", 1).c_str() );
	int freq_min = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-cpu-frequency_min.txt", 1).c_str() );

	freq_max = freq_max / 1000;
	freq_min = freq_min / 1000;

	log_file << "Max Frequency             : " << freq_max << " MHz" << endl;
	log_file << "Min Frequency             : " << freq_min << " MHz" << endl << endl;
	/*
		FREQUENCY END ---------------------------------------------------------------------------------------------------->
	*/
	log_file << "------------------- NETWORK --------------------" << endl;
	log_file << "Hostname                   : " << buffer.nodename << endl;

	/*
		NETWORK ---------------------------------------------------------------------------------------------------------->
        GATEWAY
    */
   {
		ifstream file;
		int nr = 0, i = 0;
		string interfaces[32];
		string addresses[32];
		string text;
		string final_output;
		file.open(home_path()+"/.systeminfo-files/systeminfo-gateway-names.txt");
		if (file.good() == true) {
			while(!file.eof()) {
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
		unsigned int tmpMask;

		string netmask_output, address_output;

		getifaddrs(&ifAddrStruct);
		/*
			ADDRESS AND NETMASK END
			ADDRESS AND NETMASK OUTPUT
		*/
		for(ifa = ifAddrStruct;  ifa != NULL; ifa = ifa->ifa_next) {
			if (!ifa->ifa_addr) continue;
			if (ifa->ifa_addr->sa_family == AF_INET) {
				char address_buffer[INET_ADDRSTRLEN];
				char mask_buffer[INET_ADDRSTRLEN];

				tmpAddrPtr = &((struct sockaddr_in *)(ifa->ifa_addr))->sin_addr;
				inet_ntop(AF_INET, tmpAddrPtr, address_buffer, INET_ADDRSTRLEN);

				tmpAddrPtr = &((struct sockaddr_in *)(ifa->ifa_netmask))->sin_addr;
				inet_ntop(AF_INET, tmpAddrPtr, mask_buffer, INET_ADDRSTRLEN);

				tmpMask = ((struct sockaddr_in *)(ifa->ifa_netmask))->sin_addr.s_addr;

				address_output = "IPv4    (" + static_cast<string>(ifa->ifa_name) + ")";
				netmask_output = "Netmask (" + static_cast<string>(ifa->ifa_name) + ")";
				int count = 0;
				count = 27 - netmask_output.length();
				for(int i = 0; i < count; i++) {
					address_output = address_output + " ";
					netmask_output = netmask_output + " ";
				}
				log_file << address_output << ": " << address_buffer << endl;
				log_file << netmask_output << ": " << mask_buffer <<  endl;
				/*
					ADDRESS AND NETMASK OUTPUT END
					GATEWAY OUTPUT
				*/
				if (static_cast<string>(ifa->ifa_name) == "lo") continue;
				else {
					i++;
					interfaces[i] = open_file(home_path()+"/.systeminfo-files/systeminfo-gateway-names.txt", i);
					addresses[i] = open_file(home_path()+"/.systeminfo-files/systeminfo-gateway-ip.txt", i);

					final_output = "Gateway (" + interfaces[i] + ")";
					count = 27 - final_output.length();
					for(int  x = 0; x < count; x++) {
						final_output = final_output + " ";
					}
					log_file << final_output << ": " << addresses[i] << endl;
					/*
						GATEWAY OUTPUT END
					*/
				}
			}
		}
		if (ifAddrStruct != NULL) freeifaddrs(ifAddrStruct);
	}
	/*
		NETWORK END ------------------------------------------------------------------------------------------------------>
    */

	int time_gen = clock() - countdown;
	log_file << endl << "Log generation time........: " << time_gen << " ms" << endl;

	cout << "Done" << endl;
	cout << "Generated date            : " << in_file_time << endl;
	cout << "Logs localization         : " << home_path() << "/systeminfo-files/logs" << endl;
	cout << "Name file                 : " << file_name << endl;
	cout << "Log generation time       : " << time_gen << " ms" << endl;
}