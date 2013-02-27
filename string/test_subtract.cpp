/*
 * =====================================================================================
 *
 *       Filename:  test_subtract.cpp
 *
 *    Description:  Tests string's subtract method
 *
 *        Version:  1.0
 *        Created:  02/24/2013 04:29:42 PM
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
		String test;
		test -= 'e';
		assert(test == "");
		assert(test.getLength() == 0);
	}

	{
		// Setup
		char sub[2];
		sub[0] = 'e';
		sub[1] = 'i';

		String test[3];
		test[0] = "Herp derp";
		test[1] = test[0] - sub[0];
		test[2] = test[0] - sub[1];

		// Test string 1
		assert(test[1] == "Hrp drp");
		assert(test[1].getLength() == 7);
		assert(test[1].getCapacity() == DEFAULT_STRING_CAPACITY);
		assert(test[1].isClosed());

		// Test string 2
		assert(test[2] == "Herp derp");
		assert(test[2].getLength() == 9);
		assert(test[2].getCapacity() == DEFAULT_STRING_CAPACITY);
		assert(test[2].isClosed());
	}

	{
		String test;
		test = "Blah blah blah";
		test -= 'h';
		assert(test == "Bla bla bla");
		assert(test.isClosed());
		assert(test.getLength() == 11);
	}

	{
		String test[2];
		test[0] = "abcdefg";
		test[1] = test[0] - 3;
		assert(test[1] == "abcd");
		assert(test[1].isClosed());
		assert(test[1].getLength() == 4);
	}

	{
		String test = "abcdefg";
		test -= 3;
		assert(test == "abcd");
		assert(test.isClosed());
		assert(test.getLength() == 4);
	}

	{
		String test = "aaaaaaaaaaaaaaaaaaaa aaaa";
		test -= 100;
		assert(test == "");
		assert(test.isClosed());
		assert(test.getLength() == 0);
	}

	std::cout << "Completed testing string's subtract operator!" << std::endl;

	return 0;
}
