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

// Converts input to assembly
void to_assembly(std::ifstream&, std::ofstream&);

String assembly_operator(const String&);

String i_to_s(int);

String getToken(std::ifstream&);

// Outputs help and exits
void help(void);

int main(int argc, char const* argv[])
{
	// If input file isn't present, display help and leave
	if (argc != 3) {
		std::cerr << "No input file present!" << std::endl;
		help();
	}

	std::ifstream postfix_file(argv[1]);

	// If no infix file, show help and leave
	if (!postfix_file) {
		std::cerr << "Postfix file couldn't be opened!" << std::endl;
		help();
	}

	std::ofstream assembly_file(argv[2]);

	// If file can't be opened, display help and exit
	if (!assembly_file) {
		std::cerr << "Assembly file can't be opened!" << std::endl;
		help();
	}

	// Convert input to assembly
	to_assembly(postfix_file, assembly_file);

	postfix_file.close();
	assembly_file.close();

	return 0;
}

void to_assembly(std::ifstream& in, std::ofstream& out)
{
	Stack<String> s;
	String lhs, rhs, op, tempvar, currentToken;
	int tempN = 1;

	while (!in.eof() || !s.isEmpty()) {
		if (!in.eof()) {
			currentToken = getToken(in);
			currentToken -= '\n';
		} else {
			break;
		}

		if (currentToken == ";") {
			out << "===============================" << std::endl;
			tempN = 1;
		}

		if (!in.eof() && currentToken != "+" && currentToken != "-" && currentToken != "*" && currentToken != "/") {
			s.push(currentToken);
		} else if (!in.eof()) {
			rhs = s.pop();
			lhs = s.pop();

			out << "LDR\t" << lhs << std::endl;

			op = assembly_operator(currentToken);
			out << op << rhs << std::endl;

			tempvar = "TEMP" + i_to_s(tempN++);
			s.push(tempvar);

			out << "STR\t" << tempvar << std::endl;
		}
	}
}

String assembly_operator(const String& op)
{
	switch (op[0]) {
		case '+':
			return "ADD\t";
			break;
		case '-':
			return "SUB\t";
			break;
		case '*':
			return "MUL\t";
			break;
		case '/':
			return "DIV\t";
			break;
		default:
			return "UNDEFINED\t";
	}
}

String i_to_s(int x)
{
	if (x == 0) {
		return "0";
	}

	String result;

	do {
		result += (x % 10 + 48);
		x /= 10;
	} while (x > 0);

	return result;
}

String getToken(std::ifstream& in)
{
	String result;
	char token = '\0';

	for (int i = 0; token != ' ' && !in.eof(); ++i) {
		in.get(token);

		if (token == ';') {
			return ";";
		} else if (token != ' ') {
			result += token;
		}
	}

	return result;
}

void help()
{
	std::cerr << "Usage: ./assembler.out [input file] [output file]" << std::endl;
	exit(1);
}
