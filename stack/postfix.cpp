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

#include <fstream>
#include "stack.h"
#include "../string/string.h"

// Converts infix to postfix
void to_postfix(std::ifstream&, std::ofstream&);

// Outputs help and exits
void help(void);

// ./postfix.out input.txt output.txt
int main(int argc, char const* argv[])
{
	// If input file isn't present, display help and leave
	if (argc < 2) {
		std::cerr << "No input file present!" << std::endl;
		help();
	}

	// Open the infix file
	std::ifstream infix_file(argv[1]);

	// If no infix file, show help and exit
	if (!infix_file) {
		std::cerr << "Infix file could not be opened!" << std::endl;
		help();
	}

	std::ofstream postfix_file(argv[2]);

	// If file can't be opened, display help and exit
	if (!postfix_file) {
		std::cerr << "Output file can't be opened! Please try again!" << std::endl;
		help();
	}

	to_postfix(infix_file, postfix_file);

	infix_file.close();
	postfix_file.close();

	return 0;
}

void to_postfix(std::ifstream& in, std::ofstream& out)
{
	Stack<String> s;
	String lhs,
		   rhs,
		   op,
		   currentToken;
	char token[300];

	while (!in.eof()) {
		in >> token;
		currentToken = String(token);

		if (in.eof()) {
			break;
		}

		if (currentToken == ";") {
			out << s;
			out << ";";
			out << std::endl;
			s = Stack<String>();
		} else if (currentToken == ")") {
			rhs = s.pop();
			op = s.pop();
			lhs = s.pop();
			s.push(lhs + rhs + op);
		} else {
			if (currentToken != "(") {
				s.push(currentToken + ' ');
			}
		}
	}
}

void help()
{
	std::cerr << "Usage: ./postfix.out [input file] [output file]" << std::endl;
	exit(1);
}
