/*
 * =====================================================================================
 *
 *       Filename:  postfix.cpp
 *
 *    Description:  Program that converts infix expressions to postfix
 *
 *        Version:  1.0
 *        Created:  04/01/2013 01:52:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <fstream>
#include <vector>
#include "stack.h"
#include "../string/string.h"

// Converts infix to postfix
String to_postfix(const String&);

// Outputs result
void output(std::ostream&, std::istream&);

// Outputs help and exits
void help(void);

int main(int argc, char const* argv[])
{
	// If output file isn't present, display help and leave
	if (argc < 2) {
		help();
	}

	std::ifstream infix_file;

	// Open the infix file
	infix_file.open(argv[1]);

	// If no infix file, show help and exit
	if (!infix_file) {
		std::cerr << "Infix file could not be opened!" << std::endl;
		help();
	}

	// If no output file is specified, write to cout
	if (argc != 3) {
		output(std::cout, infix_file);
	} else {
		std::ofstream postfix_file;
		postfix_file.open(argv[2]);

		// If file can't be opened, display help and exit
		if (!postfix_file) {
			std::cerr << "Output file can't be opened! Please try again!" << std::endl;
			help();
		}

		output(postfix_file, infix_file);
		postfix_file.close();
	}

	infix_file.close();

	return 0;
}

String to_postfix(const String& infix)
{
	Stack<String> s;
	String result,
		   lhs,
		   rhs,
		   op;

	std::vector<String> infix_vec = infix.split(' ');

	for (unsigned int index = 0; index < infix_vec.size(); ++index) {
		if (infix_vec[index] != '(') {
			if (infix_vec[index] == ')') {
				rhs = s.pop();
				op = s.pop();
				lhs = s.pop();
				s.push(lhs + ' ' + rhs + ' ' + op);
			} else {
				s.push(infix_vec[index]);
			}
		}
	}

	while (!s.isEmpty()) {
		result = s.pop() + result;
	}

	return result;
}

void output(std::ostream& out, std::istream& in)
{
	while (!in.eof()) {
		out << (to_postfix(getline(in))) << std::endl;
	}
}

void help()
{
	std::cout << "Usage: ./postfix [input file] [output file]" << std::endl;
	exit(1);
}
