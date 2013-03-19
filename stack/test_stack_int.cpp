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
		std::cout << "Empty Stack Test" << std::endl
				  << "Expected: " << std::endl
				  << "Result: ";

		blank_stack.printAll();
		std::cout << std::endl;
	}

	{
		Stack<int> single_stack;

		single_stack.push(1);

		std::cout << "Single Item Stack Test" << std::endl
				  << "Expected: 1" << std::endl
				  << "Result: ";

		single_stack.printAll();
		std::cout << std::endl;
	}

	{
		Stack<int> int_stack;

		int_stack.push(1);
		int_stack.push(2);
		int_stack.push(3);

		std::cout << "Move Item Stack Test" << std::endl
				  << "Expected: 3 2 1" << std::endl
				  << "Result: ";

		int_stack.printAll();
		std::cout << std::endl;
	}

	std::cout << "Completed testing int stack!" << std::endl;

	return 0;
}
