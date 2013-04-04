/*
 * =====================================================================================
 *
 *       Filename:  assembler.cpp
 *
 *    Description:  Program that converts infix to assemlby
 *
 *        Version:  1.0
 *        Created:  04/01/2013 02:41:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include <fstream>
#include "stack.h"
#include "../string/string.h"

// Outputs help and exits
void help(void);

int main(int argc, char const* argv[])
{
	// If input file isn't present, display help and leave
	if (argc != 3) {
		std::cerr << "No input file present!" << std::endl;
		help();
	}

	std::ifstream postfix_file;
	postfix_file.open(argv[1]);

	// If no infix file, show help and leave
	if (!postfix_file) {
		std::cerr << "Postfix file couldn't be opened!" << std::endl;
		help();
	}

	std::ofstream assembly_file;
	assembly_file.open(argv[2]);

	// If file can't be opened, display help and exit
	if (!assembly_file) {
		std::cerr << "Assembly file can't be opened!" << std::endl;
		help();
	}

	assembly_file.close();
	postfix_file.close();

	return 0;
}

void help()
{
	std::cerr << "Usage: ./assembler.out [input file] [output file]" << std::endl;
	exit(1);
}
