/*
 * functions_file.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include "functions_file.h"
#include "functions_file_operations.h"

using namespace std;

string distribution_file() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-distro.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	return value;
}

string release_system() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-distro.txt";
	const int line = 2;

	string value;
	value = open_file(input_value, line);

	return value;
}

string cedename_system() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-distro.txt";
	const int line = 3;

	string value;
	value = open_file(input_value, line);

	return value;
}

void cpu_file() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-cpu.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	cout << "CPU                       : " << value << endl;
}

void architecture() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-arch.txt";
	const string bit32 = "32 Bits";
	const string bit64 = "64 Bits";
	const string arm32 = "ARM 32 Bits";
	const string arm64 = "ARM 64 Bits";

	string arch, bits;
	arch = open_file(input_value, 1);
	bits = open_file(input_value, 2);

	if(bits.empty() == true)
		cout << "System architecture       : " << arch << endl;
	else
		cout << "System architecture       : " << bits << " Bits (" << arch << ")" << endl;
}

string model() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-model.txt";

	string value;
	value = open_file(input_value, 1);

	return value;
}

string motherboard() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-motherboard.txt";

	string value;
	value = open_file(input_value, 1);

	return value;
}

string motherboard_manufacturer() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-motherboard-manufact.txt";

	string value;
	value = open_file(input_value, 1);

	return value;
}

string bios_manufacturer() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-bios-manufact.txt";

	string value;
	value = open_file(input_value, 1);

	return value;
}

string bios_version() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-bios-version.txt";

	string value;
	value = open_file(input_value, 1);

	return value;
}

string bios_date() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-bios-date.txt";

	string value;
	value = open_file(input_value, 1);

	return value;
}

void shell_file() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-shell.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

		if(value == "/bin/zsh" || value == "/usr/bin/zsh")				cout << "Shell                     : Z-Shell (" << value << ")" << endl;
		else if(value == "/bin/bash" || value == "/usr/bin/bash")	cout << "Shell                     : Bash (" << value << ")" << endl;
		else if(value == "/bin/sh" || value == "/usr/bin/sh")			cout << "Shell                     : Sh (" << value << ")" << endl;
		else if(value == "/bin/dash" || value == "/usr/bin/dash")	cout << "Shell                     : Dash (" << value << ")" << endl;
		else if(value == "/bin/ksh" || value == "/usr/bin/ksh")		cout << "Shell                     : Ksh (" << value << ")" << endl;
		else if(value == "/bin/rsh" || value == "/usr/bin/rsh")		cout << "Shell                     : Rsh (" << value << ")" << endl;
		else														cout << "Shell                     : " << value << endl;
}

int theards_file() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-theards.txt";

	string value;
	value = open_file(input_value, 1);

	return atoi(value.c_str());
}

int cores_file() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-cores.txt";

	string value;
	value = open_file(input_value, 1);

	return atoi(value.c_str());
}

void cpu_frequency() {
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
                cout << "CPU Frequency             : N/A" << endl;
            else
                cout << "CPU Frequency             : " << frequency_sum << " MHz" << endl;
		}
		else {
			cout << "CPU Frequency             : N/A" << endl;
		}
	file.close();
}

void cpu_freq_max_min() {
	if(open_file(home_path() + "/.systeminfo-files/systeminfo-cpu-frequency_max.txt", 1) == "N/A") {
		cout << "Max Frequency             : N/A" << endl;
		cout << "Min Frequency             : N/A" << endl;
		return;
	}

	int freq_max = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-cpu-frequency_max.txt", 1).c_str() );
	int freq_min = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-cpu-frequency_min.txt", 1).c_str() );

	freq_max = freq_max / 1000;
	freq_min = freq_min / 1000;

	cout << "Max Frequency             : " << freq_max << " MHz" << endl;
	cout << "Min Frequency             : " << freq_min << " MHz" << endl;
}

string user_file() {
	string user = getenv("USER");
	return user;
}

string uptime_file() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-uptime.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	return value;
}

string home_path() {
	string home_path = getenv("HOME");
	return home_path;
}

string fan_speed() {
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-cpu-fan-speed.txt";

	string value;
	value = open_file(input_value, 1);

	if (value == "N/A") {
		return "N/A";
	}
	else{
		return value + " RPM";
	}
}