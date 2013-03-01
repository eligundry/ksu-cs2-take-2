/*
 * =====================================================================================
 *
 *       Filename:  test_substr.cpp
 *
 *    Description:  Test's string's substr method
 *
 *        Version:  1.0
 *        Created:  02/24/2013 07:28:33 PM
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
		String test[8];
		test[0] = "0123456789";

		test[1] = test[0].substr(0);
		test[2] = test[0].substr(5);
		test[3] = test[0].substr(0, 6);
		test[4] = test[0].substr(3, 20);
		test[5] = test[0].substr(6, 5);
		test[6] = test[0].substr(11, 20);
		test[7] = test[0].substr(0, 36);

		assert(test[1] == "0123456789");
		assert(test[1].getLength() == 10);

		assert(test[2] == "56789");
		assert(test[2].getLength() == 5);

		assert(test[3] == "012345");
		assert(test[3].getLength() == 6);

		assert(test[4] == "3456789");
		assert(test[4].getLength() == 7);

		assert(test[5] == "6789");
		assert(test[5].getLength() == 4);

		assert(test[6] == "");
		assert(test[6].getLength() == 0);

		assert(test[7] == "0123456789");
		assert(test[7].getLength() == 10);
	}

	std::cout << "Completed testing string's substr function!" << std::endl;

	return 0;
}
