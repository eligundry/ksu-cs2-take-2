/*
 * =====================================================================================
 *
 *       Filename:  test_force_overflow.cpp
 *
 *    Description:  Try to activate string's ability to handle overflows
 *
 *        Version:  1.0
 *        Created:  02/28/2013 06:20:48 PM
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
		String test("Blah", 2);
		assert(test == "Blah");
		assert(test.getCapacity() != 2);
		assert(test.getLength() == 4);
		assert(test.isClosed());
	}

	{
		String test('a', 2);
		test += "bcdefg";
		assert(test == "abcdefg");
		assert(test.getLength() == 7);
		assert(test.getCapacity() != 2);
		assert(test.isClosed());
	}

	return 0;
}
