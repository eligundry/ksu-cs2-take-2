/*
 * =====================================================================================
 *
 *       Filename:  test_reallocate.cpp
 *
 *    Description:  Tests string's reallocate function
 *
 *        Version:  1.0
 *        Created:  02/28/2013 06:38:57 PM
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
		String test("Hey now");
		assert(test.getCapacity() == DEFAULT_STRING_CAPACITY);
		test.reallocate(40);
		assert(test.getCapacity() == 40);
	}

	{
		String test("abc");
		assert(test.getCapacity() == DEFAULT_STRING_CAPACITY);
		test.reallocate(2);
		assert(test.getCapacity() == 4);
	}

	{
		String test = "Eli Gundry";
		assert(test.getCapacity() == DEFAULT_STRING_CAPACITY);
		test.reallocate(35);
		assert(test.getCapacity() == 35);
	}

	std::cout << "Completed testing string's reallocate function!" << std::endl;

	return 0;
}
