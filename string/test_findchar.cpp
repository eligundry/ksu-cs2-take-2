/*
 * =====================================================================================
 *
 *       Filename:  test_findchar.cpp
 *
 *    Description:  Tests string's findchar method
 *
 *        Version:  1.0
 *        Created:  02/22/2013 07:01:55 PM
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
	String test = "this is awesome!";

	{
		char find = 't';
		assert(test.findchar(find) == 0);
	}

	{
		char find = 'a';
		assert(test.findchar(find) == 8);
	}

	{
		assert(test.findchar('w') == 9);
		assert(test.findchar('w') == test.findchar('a') + 1);
	}

	{
		char find = 'i';
		assert(test.findchar(find) == 2);
	}

	{
		char find = 'z';
		assert(test.findchar(find) == -1);
	}

	std::cout << "Completed testing findchar method!" << std::endl;

	return 0;
}
