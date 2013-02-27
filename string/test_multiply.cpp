/*
 * =====================================================================================
 *
 *       Filename:  test_multiply.cpp
 *
 *    Description:  Test's string's multiply operator
 *
 *        Version:  1.0
 *        Created:  02/25/2013 11:19:46 AM
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
		test[0] = test[1] * 5;

		for (int i = 0; i < 2; ++i) {
			assert(test[i] == "");
			assert(test[i].getLength() == 0);
			assert(test[i].isClosed());
		}
	}

	{
		String test[4];
		test[0] = "Boom ";

		test[1] = test[0] * 0;
		test[2] = test[0] * 1;
		test[3] = test[0] * 3;

		assert(test[1] == "");
		assert(test[1].getLength() == 0);

		assert(test[2] == "Boom ");
		assert(test[2].getLength() == 5);

		assert(test[3] == "Boom Boom Boom ");
		assert(test[3].getLength() == 15);

		for (int i = 0; i < 4; ++i) {
			assert(test[i].isClosed());
		}
	}

	std::cout << "Completed testing string's multiply function!" << std::endl;

	return 0;
}
