/*
 * =====================================================================================
 *
 *       Filename:  test_zip.cpp
 *
 *    Description:  Tests string's zip function
 *
 *        Version:  1.0
 *        Created:  03/03/2013 04:43:16 PM
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
		String test[3];
		test[2] = test[0].zip(test[1]);
		assert(test[2] == "");
		assert(test[2].getLength() == 0);
		assert(test[2].isClosed());
	}

	{
		String test[3];
		test[0] = "ace";
		test[1] = "bdf";
		test[2] = test[0].zip(test[1]);
		assert(test[2] == "abcdef");
		assert(test[2].getLength() == 6);
		assert(test[2].isClosed());
	}

	{
		String test[3];
		test[0] = "02468";
		test[1] = "13579";
		test[2] = test[0].zip(test[1]);
		assert(test[2] == "0123456789");
		assert(test[2].getLength() == 10);
		assert(test[2].isClosed());
	}

	std::cout << "Completed testing string's zip function!" << std::endl;

	return 0;
}
