/*
 * =====================================================================================
 *
 *       Filename:  test_stack_int.cpp
 *
 *    Description:  Tests stacks with ints
 *
 *        Version:  1.0
 *        Created:  03/18/2013 06:10:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include "stack.h"

int main()
{
	{
		Stack<int> blank_stack;
		assert(blank_stack == Stack<int>());
		assert(blank_stack.getLength() == 0);
	}

	{
		Stack<int> test, result, blank;

		test.push(1);
		result = test;

		assert(test == result);
		assert(test != blank);

		assert(test.getLength() == 1);
		assert(result.getLength() == 1);
	}

	{
		Stack<int> test, result, blank;

		test.push(1);
		test.push(2);
		test.push(3);
		test.push(4);
		test.push(5);
		test.push(6);
		result = test;

		assert(test == result);
		assert(test != blank);

		assert(test.getLength() == 6);
		assert(result.getLength() == 6);
	}

	std::cout << "Completed testing int stack!" << std::endl;

	return 0;
}
