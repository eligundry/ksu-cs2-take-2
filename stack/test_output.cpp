/*
 * =====================================================================================
 *
 *       Filename:  test_output.cpp
 *
 *    Description:  Test's queue and stacks output functions
 *
 *        Version:  1.0
 *        Created:  03/19/2013 07:24:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include "stack.h"
#include "queue.h"
#include "../string/string.h"

int main()
{
	{
		Stack<int> empty_stack;
		std::cout << empty_stack << std::endl;
	}

	{
		Stack<int> single_stack;
		single_stack.push(1);

		std::cout << single_stack << std::endl;
	}

	{
		Stack<int> big_stack;
		big_stack.push(1);
		big_stack.push(2);
		big_stack.push(3);
		big_stack.push(4);
		big_stack.push(5);

		std::cout << big_stack << std::endl;
	}

	{
		Stack<String> str_stack;
		String items[3];

		items[0] = "Eli";
		items[1] = "is";
		items[2] = "awsome!";

		str_stack.push(items[0]);
		str_stack.push(items[1]);
		str_stack.push(items[2]);

		std::cout << str_stack << std::endl;
	}

	{
		Queue<int> empty_queue;
		std::cout << empty_queue << std::endl;
	}

	{
		Queue<int> single_queue;
		single_queue.enqueue(1);

		std::cout << single_queue << std::endl;
	}

	{
		Queue<int> big_queue;
		big_queue.enqueue(1);
		big_queue.enqueue(2);
		big_queue.enqueue(3);
		big_queue.enqueue(4);
		big_queue.enqueue(5);
		big_queue.enqueue(6);

		std::cout << big_queue << std::endl;
	}

	{
		Queue<String> str_queue;
		String items[3];

		items[0] = "Eli";
		items[1] = "is";
		items[2] = "awsome!";

		str_queue.enqueue(items[0]);
		str_queue.enqueue(items[1]);
		str_queue.enqueue(items[2]);

		std::cout << str_queue << std::endl;
	}

	std::cout << "Completed testing stack and queue's output functions!" << std::endl;

	return 0;
}
