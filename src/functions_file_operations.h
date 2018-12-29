/*
 * function_open_file.h
 *
 *  Created on: Dec 17, 2018
 *      Author: krupier
 */

#ifndef FUNCTION_OPEN_FILE_H_
#define FUNCTION_OPEN_FILE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

	string open_file(string path_file, int nr_line);
	void check_file_text(string input, string search_text);
	void find_text( string & text, string find_string );

#endif /* FUNCTION_OPEN_FILE_H_ */