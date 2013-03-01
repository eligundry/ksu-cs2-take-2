/*
 * =====================================================================================
 *
 *       Filename:  test_default_ctor.cpp
 *
 *    Description:  Tests the default constructor for string
 *
 *        Version:  1.0
 *        Created:  02/21/2013 06:26:36 PM
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
		// Setup
		String test;

		// Testing
		assert(test == "");
		assert(test[0] == '\0');
		assert(test.getLength() == 0);
		assert(test.getCapacity() == DEFAULT_STRING_CAPACITY);
		assert(test.isClosed());
	}

	{
		String test(60);
		assert(test == "");
		assert(test[0] == '\0');
		assert(test.getLength() == 0);
		assert(test.getCapacity() == 60);
		assert(test.isClosed());
	}

	std::cout << "Completed testing string's default constructor!" << std::endl;

	return 0;
}

