/*
 * =====================================================================================
 *
 *       Filename:  test_next_blank.cpp
 *
 *    Description:  Tests string's blank/non-blank finding functions
 *
 *        Version:  1.0
 *        Created:  03/07/2013 05:42:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include "string.h"
#include <cassert>

int main()
{
	{
		String test = "This is awesome!";
		assert(test.nextBlank() == 4);
		assert(test.nextBlank(5) == 7);
		assert(test.nextNonBlank() == 0);
		assert(test.nextNonBlank(test.nextBlank()) == 5);
	}

	{
		String test = "This  string has     some weird spacing.";
		assert(test.nextBlank() == 4);
		assert(test.nextBlank(test.nextBlank() + 1) == 5);
		assert(test.nextBlank(test.nextBlank(test.nextBlank() + 1) + 1) == 12);
	}

	std::cout << "Completed testing string's next blank functions!" << std::endl;

	return 0;
}
