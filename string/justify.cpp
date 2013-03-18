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
String justify(String, int, int);
String getWord(String&);
String insertSpaces(int, bool);

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
	String input, result;
	in >> input;
	result = justify(input, left, right);

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

String justify(String str, int left, int right)
{
	String result,
		   currentLine,
		   currentWord;

	int width = right - left + 1;

	// Indent the first line
	result += insertSpaces(left, false);

	for (currentWord = getWord(str); currentWord != ""; currentWord = getWord(str)) {
		if (currentWord.findstr("\n") == 2) {
			currentLine += currentWord.substr(0, currentWord.findchar('\n'));
			result += currentLine.justify(width);
			result += insertSpaces(left, true);
			currentLine = "";
			currentWord = currentWord.substr(currentWord.findchar('\n') + 1);
		} else if (currentWord.findstr("\n") == 1) {
			std::vector<String> temp = currentWord.split('\n');
			currentLine += temp[0];
			result += currentLine.justify(width);
			result += insertSpaces(left, true);
			currentLine = "";
			currentWord = temp[1];
		}

		if (currentLine.getLength() + currentWord.getLength() + 1 <= width) {
			currentLine += currentWord;
			currentLine += ' ';
		} else {
			result += currentLine.justify(width);
			result += insertSpaces(left, true);
			currentLine = currentWord;
			currentLine += ' ';
		}
	}

	return result;
}

String getWord(String& str)
{
	String word;

	if (str.getLength() != 0) {
		word = str.substr(0, str.nextBlank());
		str = str.substr(str.nextNonBlank(word.getLength()));
	}

	return word;
}

String insertSpaces(int spaces, bool addNewLine)
{
	String result;

	if (addNewLine) {
		result += '\n';
	}

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
