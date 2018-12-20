/*
 * function_open_file.cpp
 *
 *  Created on: Dec 17, 2018
 *      Author: krupier
 */
#include "function_open_file.h"

using namespace std;

string open_file(string path_file, int nr_line) {
	string line;

	ifstream file(path_file.c_str());

	if(file.good() == false) {
		cout << "systeminfo: Not found file in /systeminfo-files" << endl;
		return 0;
	}

	for(int i = 0; i < nr_line; i++)
	{
		getline(file, line);
	}

	file.close();

	return line;
}
