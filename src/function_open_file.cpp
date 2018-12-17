/*
 * function_open_file.cpp
 *
 *  Created on: Dec 17, 2018
 *      Author: krupier
 */
#include "function_open_file.h"

using namespace std;

string open_file(string path_file) {
	string line, read_file;
	int nr_line=1;

	ifstream file(path_file.c_str());

	if(file.good() == false)	cout << "Error 002: Not found file \"systeminfo-distro.txt\"" << endl;

	while (getline(file, line)) {
	switch (nr_line) {
		case 1: read_file=line; break;
	}
	nr_line++;
	}

	file.close();

	return read_file;
}
