/*
 * =====================================================================================
 *
 *       Filename:  justify.cpp
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
String justify(std::istream&, int, int);
String insertSpaces(int);

// ./justify 10 50 input.txt output.txt
int main(int argc, char const* argv[])
{
	// Check the count of arguments
	if (argc < 4) {
		help();
	}

	// Gets the input file
	std::ifstream in(argv[3]);

	// Checks if input file is valid
	if (!in) {
		std::cerr << "Couldn't open file '" << argv[3] << "'. Please try again." << std::endl;
		help();
	}

	int left = atoi(argv[1]),
		right = atoi(argv[2]);

	if (left < 0 || right > 99 || left >= right) {
		std::cerr << "You're width parameters are invalid, please try again." << std::endl;
		help();
	}

	// Justify text
	String result = justify(in, left, right);

	in.close();

	// Outputs the justify stuff
	if (argc == 4) {
		std::cout << result << std::endl;
	} else if (argc == 5) {
		std::ofstream out(argv[4]);

		if (!out) {
			std::cerr << "Couldn't open file '" << argv[4] << "' for writing. Please try again." << std::endl;
			help();
		}

		out << result;
		out.close();
	}

	return 0;
}

String justify(std::istream& in, int left, int right)
{
	String result,
		   currentLine,
		   currentWord;

	char word[300];

	int width = right - left + 1;

	while (!in.eof()) {
		in >> word;
		currentWord = String(word);

		if (in.eof()) {
			break;
		}

		if (currentLine.getLength() + currentWord.getLength() + 1 <= width) {
			if (currentLine == "") {
				currentLine = currentWord;
			} else {
				currentLine += ' ' + currentWord;
			}
		} else {
			currentLine = currentLine.justify(width);
			result += insertSpaces(left) +  currentLine + '\n';
			currentLine = currentWord;
		}
	}

	return result;
}

String insertSpaces(int spaces)
{
	String result;

	for (int index = 0; index <= spaces; ++index) {
		result += ' ';
	}

	return result;
}

void help()
{
	std::cout << "Usage: " << std::endl;
	std::cout << "\t./justify [left] [right] [input] [output]" << std::endl;
	std::cout << "\tleft: integer value of the left offset." << std::endl;
	std::cout << "\tright: integer value of the right offset." << std::endl;
	std::cout << "\tinput: file of text to be justified." << std::endl;
	std::cout << "\toutput: optional file where justified text will be written. If not specified, text will be printed to screen." << std::endl;
	exit(1);
}
