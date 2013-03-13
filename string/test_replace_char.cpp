/*
 * =====================================================================================
 *
 *       Filename:  test_replace_char.cpp
 *
 *    Description:  Tests string's replaceChar function
 *
 *        Version:  1.0
 *        Created:  03/12/2013 02:32:51 PM
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
		String test[2];
		test[0] = "aaaaaaaaaaaaaaaaaaaa";
		test[1] = test[0].replaceChar('a', 'b');
		assert(test[1] == "bbbbbbbbbbbbbbbbbbbb");
		assert(test[1].getLength() == 20);
		assert(test[1].isClosed());
	}

	{
		String test[2];
		test[0] = "This is line 1.\nThis is line 2.";
		test[1] = test[0].replaceChar('\n', ' ');
		assert(test[1] == "This is line 1. This is line 2.");
		assert(test[1].getLength() == 31);
		assert(test[1].isClosed());
	}

	{
		String test[2];
		test[0] = "This is line 1\nThis is line 2\n";
		test[1] = test[0].replaceChar('\n', ". ");
		assert(test[1] == "This is line 1. This is line 2. ");
		assert(test[1].getLength() == 32);
		assert(test[1].isClosed());
	}

    std::cout << "Completed testing string's replace char function!" << std::endl;

	return 0;
}
