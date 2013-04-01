/*
 * =====================================================================================
 *
 *       Filename:  test_queue_string.cpp
 *
 *    Description:  Tests queue with the string datatype
 *
 *        Version:  1.0
 *        Created:  04/01/2013 01:47:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include "queue.h"
#include "../string/string.h"

int main()
{
	{
		Queue<String> blank_queue;
		assert(blank_queue == Queue<String>());
		assert(blank_queue.getLength() == 0);
	}

	{
		Queue<String> test, result, blank;
		String item = "Eli";

		test.enqueue(item);
		result = test;

		assert(test == result);
		assert(test != blank);

		assert(test.getLength() == 1);
		assert(result.getLength() == 1);
	}

	{
		Queue<String> test, result, blank;
		String item[3];

		item[0] = "Eli";
		item[1] = "is";
		item[2] = "awesome!";

		test.enqueue(item[0]);
		test.enqueue(item[1]);
		test.enqueue(item[2]);

		result = test;

		assert(test == result);
		assert(test != blank);

		assert(test.getLength() == 3);
		assert(result.getLength() == 3);
	}

	std::cout << "Completed testing queue with the string datatype!" << std::endl;

	return 0;
}
