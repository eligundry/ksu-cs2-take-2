/*
 * =====================================================================================
 *
 *       Filename:  test_add.cpp
 *
 *    Description:  Tests string's addition operator
 *
 *        Version:  1.0
 *        Created:  02/22/2013 02:13:19 PM
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
		String test[3];
		test[2] = test[0] + test[1];
		assert(test[2] == "");
		assert(test[2].getLength() == 0);
		assert(test[2].isClosed());
	}

	{
		String test[3];
		test[0] = "take part 1 ";
		test[1] = "and add part 2 to it";
		test[2] = test[0] + test[1];
		assert(test[0] == "take part 1 ");
		assert(test[1] == "and add part 2 to it");
		std::cout << "'" << test[2] << "' " << test[2].getLength() << std::endl;
		assert(test[2] == "take part 1 and add part 2 to it");
		assert(test[2].getLength() == 32);
		assert(test[2].isClosed());
	}

	{
		String test[2];
		test[0] = "herp ";
		test[1] = test[0] + "derp";
		assert(test[0] == "herp ");
		assert(test[1] == "herp derp");
		assert(test[1].getLength() == 9);
		assert(test[1].isClosed());
	}

	{
		String test[2];
		test[0] = "herp derp";
		test[1] = test[0] + '!';
		assert(test[0] == "herp derp");
		assert(test[1] == "herp derp!");
		assert(test[1].getLength() == 10);
		assert(test[1].isClosed());
	}

	{
		String test[3];
		test[0] = test[2] = "herp ";
		test[1] = "derp!";
		test[2] += test[1];
		assert(test[0] == "herp ");
		assert(test[1] == "derp!");
		assert(test[2] == "herp derp!");
		assert(test[2].getLength() == 10);
		assert(test[2].isClosed());
	}

	{
		String test = "herp derp";
		test += '!';
		assert(test == "herp derp!");
		assert(test.getLength() == 10);
		assert(test.isClosed());
	}

	{
		String test[2];
		test[0] = "ing";
		test[1] = "th" + test[0];
		assert(test[1] == "thing");
		assert(test[1].isClosed());
		assert(test[1].getLength() == 5);
	}

	{
		String test[2];
		test[0] = "hing";
		test[1] = 't' + test[0];
		assert(test[1] == "thing");
		assert(test[1].isClosed());
		assert(test[1].getLength() == 5);
	}

	std::cout << "Completed testing string's addition operator" << std::endl;

	return 0;
}
