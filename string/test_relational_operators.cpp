/*
 * =====================================================================================
 *
 *       Filename:  test_relational_operators.cpp
 *
 *    Description:  Tests string's relational operators
 *
 *        Version:  1.0
 *        Created:  02/22/2013 01:08:14 PM
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
		test[0] = "blag";
		test[1] = "blah";
		assert(test[0] < test[1]);
		assert(test[1] > test[0]);
	}

	{
		String test[2];
		test[0] = "testing string is fun";
		test[1] = "testing string is fun";
		assert(test[0] <= test[1]);
		assert(test[0] >= test[1]);
	}

	std::cout << "Completed testing string's relational operators!" << std::endl;

	return 0;
}
