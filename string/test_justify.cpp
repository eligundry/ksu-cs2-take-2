/*
 * =====================================================================================
 *
 *       Filename:  test_justify.cpp
 *
 *    Description:  Tests string's justify function
 *
 *        Version:  1.0
 *        Created:  03/08/2013 02:42:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include "string.h"
#include <cassert>
#include <fstream>

int main()
{
	{
		String input, expected;
		input = "This is not a test file";
		expected = input.justify(0, 40);
		assert(expected == "This     is    not    a    test    file.");
	}

	std::cout << "Completed testing string's justify method!" << std::endl;

	return 0;
}
