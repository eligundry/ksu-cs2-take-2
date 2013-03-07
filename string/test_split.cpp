/*
 * =====================================================================================
 *
 *       Filename:  test_split.cpp
 *
 *    Description:  Tests string's split function
 *
 *        Version:  1.0
 *        Created:  03/07/2013 02:27:48 PM
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
	String test = "This is the most awesome thing ever!";

	{
		std::vector<String> result = test.split();

		for (int i = 0; i < test.getLength(); ++i) {
			assert(String(test[i]) == result[i]);
		}
	}

	{
		std::vector<String> result = test.split(' ');

		assert(result[0] == "This");
		assert(result[1] == "is");
		assert(result[2] == "the");
		assert(result[3] == "most");
		assert(result[4] == "awesome");
		assert(result[5] == "thing");
		assert(result[6] == "ever!");
	}

	std::cout << "Completed testing string's split function!" << std::endl;

	return 0;
}
