/*
 * =====================================================================================
 *
 *       Filename:  test_reverse.cpp
 *
 *    Description:  Tests string's reverse function
 *
 *        Version:  1.0
 *        Created:  03/04/2013 04:58:03 PM
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
		test[0] = "";
		test[1] = test[0].reverse();
		assert(test[1] == "");
		assert(test[1].isClosed());
	}

	{
		String test[2];
		test[0] = "abcdefghijk";
		test[1] = test[0].reverse();
		assert(test[1] == "kjihgfedcba");
		assert(test[1].isClosed());
	}

	{
		String test[2];
		test[0] = "0123456789";
		test[1] = test[0].reverse();
		assert(test[1] == "9876543210");
		assert(test[1].isClosed());
	}

	std::cout << "Completed testing string's reverse function!" << std::endl;

	return 0;
}
