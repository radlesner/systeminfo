/*
 * output_memory.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: krupier
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/utsname.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <cstring>

#include "functions_output.h"
#include "functions_file.h"
#include "functions_output_memory.h"
#include "functions_file_memory.h"

using namespace std;

void output_memory_megabyte() {
	cout.precision(3);
	mem_megabyte_file();
	swap_megabyte_file();
}
