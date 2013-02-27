/*
 * =====================================================================================
 *
 *       Filename:  test_division.cpp
 *
 *    Description:  Test's string's division operator
 *
 *        Version:  1.0
 *        Created:  02/25/2013 10:57:12 AM
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
		test[1] = test[0] / 0;
		test[2] = test[0] / 1;

		for (int i = 0; i < 3; ++i) {
			assert(test[i] == "");
			assert(test[i].getLength() == 0);
			assert(test[i].isClosed());
		}
	}

	{
		String test[5];
		test[0] = "abcdefgh";
		test[1] = test[0] / 1;
		test[2] = test[0] / 0;
		test[3] = test[0] / 5;
		test[4] = test[0] / 100;

		assert(test[0] == "abcdefgh");
		assert(test[0].getLength() == 8);
		assert(test[0].isClosed());

		assert(test[1] == "bcdefgh");
		assert(test[1].getLength() == 7);
		assert(test[1].isClosed());

		assert(test[2] == "abcdefgh");
		assert(test[2].getLength() == 8);
		assert(test[2].isClosed());

		assert(test[3] == "fgh");
		assert(test[3].getLength() == 3);
		assert(test[3].isClosed());

		assert(test[4] == "");
		assert(test[4].getLength() == 0);
		assert(test[4].isClosed());
	}

	{
		String test = "abcdefgh";
		test /= 3;

		assert(test == "defgh");
		assert(test.getLength() == 5);
		assert(test.isClosed());
	}

	std::cout << "Completed testing string's division operator!" << std::endl;

	return 0;
}
