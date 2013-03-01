/*
 * =====================================================================================
 *
 *       Filename:  test_input.cpp
 *
 *    Description:  Tests string's input method
 *
 *        Version:  1.0
 *        Created:  02/24/2013 06:23:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Eli Gundry
 *
 * =====================================================================================
 */

#include "string.h"
#include <cassert>
#include <fstream>

int main()
{
	std::ifstream in("input-test-data.md");

	if (!in) {
		std::cerr << "Couldn't open input-test-data.txt, exiting!" << std::endl;
		std::exit(1);
	}

	{
		String input;
		in >> input;
		std::cout << "'" << input << "' " << input.getLength() << std::endl;
		assert(input == "Raw denim typewriter hella officia cillum, brooklyn vero lomo church-key beard ad pop-up.\n");
	}

	in.close();

	std::cout << "Completed testing string's input functions!" << std::endl << std::endl;

	return 0;
}
