/*
 * =====================================================================================
 *
 *       Filename:  justifiy.cpp
 *
 *    Description:  Program to justify text
 *
 *        Version:  1.0
 *        Created:  03/13/2013 08:45:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include "string.h"
#include <fstream>

void help();
String justify(const String, String&, int, int);
String getLine(std::istream&);

// ./justifiy 10 50 input.txt output.txt
int main(int argc, char const* argv[])
{
	// Check the count of arguments
	if (argc < 3) {
		help();
	}

	// Gets the input file
	std::ifstream in(argv[2]);

	// Checks if input file is valid
	if (!in) {
		std::cerr << "Couldn't open file '" << argv[2] << "'. Please try again." << std::endl;
		exit(1);
	}

	int left = int(argv[0]) - int('0'),
		right = int(argv[1]) - int('0');

	String result,
		   currentLine,
		   remainder;

	do {
		if (!in.eof()) {
			currentLine = getLine(in);
		} else {
			currentLine = "";
		}

		result += justify(currentLine, remainder, left, right);
	} while (!in.eof() && remainder.getLength() == 0);

	in.close();

	// Outputs the justifiy stuff
	if (argc == 3) {
		std::cout << result << std::endl;
	} else if (argc == 4) {
		std::ofstream out(argv[3]);

		if (!out) {
			std::cerr << "Couldn't open file '" << argv[3] << "' for writing. Please try again." << std::endl;
			exit(1);
		}

		out << result;
		out.close();
	}

	return 0;
}

String justify(const String line, String& remainder, int left, int right)
{
	String result;

	int width = right - left + 1;

	for (int index = 0; index < left; ++index) {
		result += ' ';
	}

	result += '\n';

	return result;
}

String getLine(std::istream& in)
{
	String result;
	char ch = 0;

	in.get(ch);

	for (int index = 0; ch != '\n' && !in.fail(); ++index, in.get(ch)) {
		result += ch;
	}

	return result;
}

void help()
{
	std::cout << "Usage: " << std::endl;
	std::cout << "\t./justifiy [left] [right] [input] [output]" << std::endl;
	std::cout << "\tleft: integer value of the left offset." << std::endl;
	std::cout << "\tright: integer value of the right offset." << std::endl;
	std::cout << "\tinput: file of text to be justified." << std::endl;
	std::cout << "\toutput: optional file where justified text will be written. If not specified, text will be printed to screen." << std::endl;
	exit(1);
}
