/*
 * function_open_file.cpp
 *
 *  Created on: Dec 17, 2018
 *      Author: krupier
 */
#include "function_open_file.h"

using namespace std;

extern int string_confirmed; /*--------------------/ Global Variable /--------------------*/

string open_file(string path_file, int nr_line) {
	string line;
	ifstream file;

	file.open(path_file.c_str());

	if(file.good() == false) {
		cout << "systeminfo: Not found file in /systeminfo-files" << endl;
		return 0;
	}

	for(int i = 0; i < nr_line; i++)
		getline(file, line);

	file.close();

	return line;
}

void check_available() {
	string line;
	int nr_line=1;

	string read[100];
	ifstream file;

	file.open("/proc/meminfo");

	if(file.good() == false)
		string_confirmed = 0;

	while (getline(file, line)) {
		switch (nr_line) {
			case 1: read[1]=line; break;
			case 2: read[2]=line; break;
			case 3: read[3]=line; break;
			case 4: read[4]=line; break;
			case 5: read[5]=line; break;
			case 6: read[6]=line; break;
			case 7: read[7]=line; break;
			case 8: read[8]=line; break;
			case 9: read[9]=line; break;
			case 10: read[10]=line; break;
			case 11: read[11]=line; break;
			case 12: read[12]=line; break;
			case 13: read[13]=line; break;
			case 14: read[14]=line; break;
			case 15: read[15]=line; break;
			case 16: read[16]=line; break;
			case 17: read[17]=line; break;
			case 18: read[18]=line; break;
			case 19: read[19]=line; break;
			case 20: read[20]=line; break;
			case 21: read[21]=line; break;
			case 22: read[22]=line; break;
			case 23: read[23]=line; break;
			case 24: read[24]=line; break;
			case 25: read[25]=line; break;
			case 26: read[26]=line; break;
			case 27: read[27]=line; break;
			case 28: read[28]=line; break;
			case 29: read[29]=line; break;
			case 30: read[20]=line; break;
			case 31: read[21]=line; break;
			case 32: read[22]=line; break;
			case 33: read[23]=line; break;
			case 34: read[24]=line; break;
			case 35: read[25]=line; break;
			case 36: read[26]=line; break;
			case 37: read[27]=line; break;
			case 38: read[28]=line; break;
			case 39: read[29]=line; break;
		}
		nr_line++;
	}

	file.close();

	for(int i = 1; i <= 12; i++) {
		find_string_file(read[i], "MemAvailable:");
		if(string_confirmed == 1) {
			break;
		}
	}
}

void find_string_file( string & text, string find_string )
{
    size_t position = text.find(find_string);
    if(position == string::npos) {
        string_confirmed = 0;
        return;
    }

    do {
        string_confirmed = 1;
        position = text.find(find_string, position + find_string.size());
    } while(position != string::npos);

}
