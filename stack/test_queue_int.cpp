/*
 * =====================================================================================
 *
 *       Filename:  test_queue_int.cpp
 *
 *    Description:  Tests queue with ints
 *
 *        Version:  1.0
 *        Created:  03/19/2013 03:38:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include "queue.h"

int main()
{
	{
		Queue<int> blank_queue;
		assert(blank_queue == Queue<int>());
		assert(blank_queue.getLength() == 0);
	}

	std::cout << "Completed testing queue!" << std::endl;

	return 0;
}
