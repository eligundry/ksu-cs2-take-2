/*
 * =====================================================================================
 *
 *       Filename:  test_findstring.cpp
 *
 *    Description:  Tests string's findstring method
 *
 *        Version:  1.0
 *        Created:  02/22/2013 06:27:22 PM
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
	String test = "this is awesome";

	{
		String find = "eli";
		assert(test.findstr(find) == 0);
	}

	{
		String find = "is";
		assert(test.findstr(find) == 2);
	}

	{
		String find = "awe";
		assert(test.findstr(find) == 1);
	}

	{
		assert(test.findstr("this") == 1);
	}

	std::cout << "Completed testing the findstring method!" << std::endl;

	return 0;
}
