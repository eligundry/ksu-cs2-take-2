/*
 * =====================================================================================
 *
 *       Filename:  test_copy_constructor.cpp
 *
 *    Description:  Tests string's copy constructor
 *
 *        Version:  1.0
 *        Created:  02/24/2013 01:58:30 PM
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
		String test[2];
		test[0] = test[1];

		for (int i = 0; i <= 1; ++i) {
			assert(test[i] == "");
			assert(test[i].getLength() == 0);
			assert(test[i].getCapacity() == DEFAULT_STRING_CAPACITY);
			assert(test[i].isClosed());
		}
	}

	{
		String test[2];
		test[0] = 'a';
		test[1] = test[0];

		for (int i = 0; i <= 1; ++i) {
			assert(test[i] == "a");
			assert(test[i].getLength() == 1);
			assert(test[i].getCapacity() == DEFAULT_STRING_CAPACITY);
			assert(test[i].isClosed());
		}
	}

	{
		String test[2];
		test[0] = "Eli Gundry";
		test[1] = test[0];

		for (int i = 0; i <= 1; ++i) {
			assert(test[i] == "Eli Gundry");
			assert(test[i].getLength() == 10);
			assert(test[i].getCapacity() == DEFAULT_STRING_CAPACITY);
			assert(test[i].isClosed());
		}
	}

	std::cout << "Completed testing string's copy constructor!" << std::endl;

	return 0;
}
