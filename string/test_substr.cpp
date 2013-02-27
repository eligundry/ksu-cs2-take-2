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
		// Setup
		String test[7];
		test[0] = "I'm so tired of testing! Not!";

		// Test
		test[1] = test[0].substr(0);
		test[2] = test[0].substr(1);
		test[3] = test[0].substr(0, 6);
		test[4] = test[0].substr(25, 29);
		test[5] = test[0].substr(30, 20);
		test[6] = test[0].substr(0, 100);

		// Verify
		assert(test[0] == "I'm so tired of testing! Not!");

		assert(test[1] == "I'm so tired of testing! Not!");
		assert(test[1].getLength() == 29);

		assert(test[2].getLength() == 28);
		assert(test[2] == "'m so tired of testing! Not!");

		assert(test[3] == "I'm so");
		assert(test[3].getLength() == 6);

		assert(test[4] == "Not!");
		assert(test[4].getLength() == 4);

		assert(test[5] == "");
		assert(test[5].getLength() == 0);

		assert(test[6] == "I'm so tired of testing! Not!");
		assert(test[6].getLength() == 29);

		for (int i = 0; i < 7; ++i) {
			assert(test[i].isClosed());
		}
	}
}
