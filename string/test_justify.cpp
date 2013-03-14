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

int main()
{
	{
		String input, expected;

		input = "This is my string, you like it?";
		expected = input.justify(40);

		assert(expected == "This   is   my   string,  you  like  it?");
		assert(expected.getLength() == 40);
		assert(expected.isClosed());
	}

	std::cout << "Completed testing string's justify method!" << std::endl;

	return 0;
}
