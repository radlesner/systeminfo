/*
 * functions_file.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: krupier
 */
#include "functions_file.h"
#include "functions_file_operations.h"
#include "functions_output.h"
#include "functions_strings_operations.h"

using namespace std;

string distribution_file()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-distro.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	return value;
}

string release_system()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-release.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	return value;
}

string cedename_system()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-codename.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	return value;
}

string cpu_file()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-cpu.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	return value;
}

string architecture()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-arch.txt";

	string arch, bits, output;
	arch = open_file(input_value, 1);
	bits = open_file(input_value, 2);

	if(bits.empty() == true)
		output = arch;
	else
		output = bits + " Bits (" + arch + ")";

	return output;
}

string model()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-model.txt";

	string value;
	value = open_file(input_value, 1);

	if (value == "LENOVO" || value == "DELL" || value == "HEWLETT PACKARD" || value == "ASUS")
		value = switch_words(value);

	return value;
}

string motherboard()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-motherboard.txt";

	string value;
	value = open_file(input_value, 1);

	if (value == "LENOVO" || value == "DELL" || value == "HEWLETT PACKARD" || value == "ASUS")
		value = switch_words(value);

	return value;
}

string motherboard_manufacturer()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-motherboard-manufact.txt";

	string value;
	value = open_file(input_value, 1);

	if (value == "LENOVO" || value == "DELL" || value == "HEWLETT PACKARD" || value == "ASUS")
		value = switch_words(value);

	return value;
}

string bios_manufacturer()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-bios-manufact.txt";

	string value;
	value = open_file(input_value, 1);

	if (value == "LENOVO" || value == "DELL" || value == "HEWLETT PACKARD" || value == "ASUS")
		value = switch_words(value);

	return value;
}

string bios_version()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-bios-version.txt";

	string value;
	value = open_file(input_value, 1);

	return value;
}

string bios_date()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-bios-date.txt";

	string value;
	value = open_file(input_value, 1);

	return value;
}

string shell_file()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-shell.txt";
	const int line = 1;

	string value, output;
	value = open_file(input_value, line);

	if(value == "/bin/zsh" || value == "/usr/bin/zsh")          output = "Z-Shell (" + value + ")";
	else if(value == "/bin/bash" || value == "/usr/bin/bash")   output = "Bash (" + value + ")";
	else if(value == "/bin/sh" || value == "/usr/bin/sh")       output = "Sh (" + value + ")";
	else if(value == "/bin/dash" || value == "/usr/bin/dash")   output = "Dash (" + value + ")";
	else if(value == "/bin/ksh" || value == "/usr/bin/ksh")     output = "Ksh (" + value + ")";
	else if(value == "/bin/rsh" || value == "/usr/bin/rsh")     output = "Rsh (" + value + ")";
	else                                                        output = value;

	return output;
}

int theards_file()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-theards.txt";

	string value;
	value = open_file(input_value, 1);

	return atoi(value.c_str());
}

int cores_file()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-cores.txt";

	string value;
	value = open_file(input_value, 1);

	return atoi(value.c_str());
}

int cpu_frequency()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-cpu-status.txt";

	if (distribution_file() == "Raspbian GNU/Linux" || distribution_file() == "Raspbian")
		return 0;

	int cores = theards_file();
	int frequency_sum = 0;

	string read_value;
	int value[512];

	fstream file;

    file.open(input_value, ios::in);
		if(file.good() == true)
		{
			for(int x = 0; x < cores; x++)
			{
				getline(file, read_value);
				if(read_value == "N/A") break;
				value[x++] = atoi(read_value.c_str());

				frequency_sum = frequency_sum + value[x];
			}
            for(int i = 0; i < cores; i++)
			{
                frequency_sum = frequency_sum + value[i];
            }

            frequency_sum = frequency_sum / cores / 1000;

			return frequency_sum;

		}
		else
		{
			return 0;
		}
	file.close();

	return 0;
}

int cpu_freq_max()
{
	if(open_file(home_path() + "/.systeminfo-files/systeminfo-cpu-frequency_max.txt", 1) == "N/A") {
		return 0;
	}

	int freq_max = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-cpu-frequency_max.txt", 1).c_str() );
	freq_max = freq_max / 1000;

	return freq_max;
}

int cpu_freq_min()
{
	if(open_file(home_path() + "/.systeminfo-files/systeminfo-cpu-frequency_min.txt", 1) == "N/A") {
		return 0;
	}

	int freq_min = atoi( open_file(home_path() + "/.systeminfo-files/systeminfo-cpu-frequency_min.txt", 1).c_str() );
	freq_min = freq_min / 1000;

	return freq_min;
}

string user_file()
{
	string user = getenv("USER");
	return user;
}

string uptime_file()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-uptime.txt";
	const int line = 1;

	string value;
	value = open_file(input_value, line);

	return value;
}

string home_path()
{
	string home_path = getenv("HOME");
	return home_path;
}

void temperatures()
{
	int nr_line = 1;
	int count_folders = atoi(open_file(home_path() + "/.systeminfo-files/systeminfo-hwmon-exist.txt", nr_line).c_str());
	int temperature[10];
	string name_temperature[10];
	string hwmon_path[count_folders];
	string string_numbers[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

	for (int i = 0; i < count_folders; i++)
	{
		hwmon_path[i] = "/sys/class/hwmon/hwmon" + string_numbers[i] + "/";
	}

	for (int i = 0; i < count_folders; i++)
	{
		if (check_file_folder_exist(hwmon_path[i] + "temp1_input") == true)
		{
			name_temperature[i] = open_file(hwmon_path[i] + "name", nr_line);
			temperature[i] = atoi( open_file(hwmon_path[i] + "temp1_input", nr_line).c_str() );
			temperature[i] = temperature[i] / 1000;

			if (name_temperature[i] == "acpitz")
			{
				name_temperature[i] = "Socket sensor";
			}
			else if (name_temperature[i] == "coretemp")
			{
				name_temperature[i] = "CPU sensor";
			}

			cout << bold() << name_temperature[i] << bold_end() << ": " << temperature[i] << " \u00B0C" << endl;

			if (count_folders - i == 1)
				separator("");
		}
	}
}

string fan_speed()
{
	const string input_value = home_path() + "/.systeminfo-files/systeminfo-cpu-fan-speed.txt";

	string value;
	value = open_file(input_value, 1);

	if (value == "N/A")
	{
		return "N/A";
	}
	else
	{
		return value + " RPM";
	}
}