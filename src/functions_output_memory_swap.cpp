/*
 * output_memory.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: krupier
 */
#include "functions_output_memory_swap.h"
#include "functions_file_memory.h"
#include "functions_file_swap.h"

using namespace std;

void output_memory() {
	mem_file();
	swap_file();
}

void output_memory_megabyte() {
	mem_megabyte_file();
	swap_megabyte_file();
}
