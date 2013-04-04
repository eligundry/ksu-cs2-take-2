/*
 * =====================================================================================
 *
 *       Filename:  test_stack_string.cpp
 *
 *    Description:  Tests stack with the string datatype
 *
 *        Version:  1.0
 *        Created:  03/18/2013 08:39:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include "stack.h"
#include "../string/string.h"

int main()
{
	{
		Stack<String> blank_stack;
		assert(blank_stack == Stack<String>());
		assert(blank_stack.getLength() == 0);
	}

	{
		Stack<String> test, result, blank;
		String item = "Eli";

		test.push(item);
		result = test;

		assert(test == result);
		assert(test != blank);

		assert(test.getLength() == 1);
		assert(result.getLength() == 1);
	}

	{
		Stack<String> test, result, blank;
		String item[3];

		item[0] = "Eli";
		item[1] = "is";
		item[2] = "awesome!";

		for (int i = 0; i < 3; ++i) {
			test.push(item[i]);
		}

		result = test;

		assert(test == result);
		assert(test != blank);

		assert(test.getLength() == 3);
		assert(result.getLength() == 3);
	}

	std::cout << "Completed testing stack with string!" << std::endl;

	return 0;
}
