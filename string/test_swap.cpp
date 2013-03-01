/*
 * =====================================================================================
 *
 *       Filename:  test_swap.cpp
 *
 *    Description:  Tests string's swap function
 *
 *        Version:  1.0
 *        Created:  02/28/2013 06:10:07 PM
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
		test[0] = "one";
		test[1] = "zero";

		test[0].swap(test[1]);

		assert(test[0] == "zero");
		assert(test[0].getLength() == 4);

		assert(test[1] == "one");
		assert(test[1].getLength() == 3);
	}

	{
		String test[2];
		test[0] = "Not blank";
		test[1].swap(test[0]);

		assert(test[0] == "");
		assert(test[1] == "Not blank");
	}

	std::cout << "Completed testing string's swap method!" << std::endl;

	return 0;
}
