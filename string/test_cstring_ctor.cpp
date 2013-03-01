/*
 * =====================================================================================
 *
 *       Filename:  test_cstring_ctor.cpp
 *
 *    Description:  Tests the string constructor with C style strings
 *
 *        Version:  1.0
 *        Created:  02/21/2013 07:20:50 PM
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
		String test('a');

		// Test
		assert(test == "a");
		assert(test[0] == 'a');
		assert(test.getLength() == 1);
		assert(test.getCapacity() == DEFAULT_STRING_CAPACITY);
		assert(test.isClosed());
	}

	{
		// Setup
		String test = 'a';

		// Test
		assert(test == "a");
		assert(test[0] == 'a');
		assert(test.getLength() == 1);
		assert(test.getCapacity() == DEFAULT_STRING_CAPACITY);
		assert(test.isClosed());
	}

	{
		// Setup
		String s = "ab";

		// Test
		assert(s == "ab");
		assert(s[0] == 'a');
		assert(s != "a");
		assert(s.getLength() == 2);
		assert(s.getCapacity() == DEFAULT_STRING_CAPACITY);
		assert(s.isClosed());
	}

	{
		// Setup
		String s("abcdeznutz");

		// Test
		assert(s == "abcdeznutz");
		assert(s[0] == 'a');
		assert(s.getLength() == 10);
		assert(s.isClosed());
	}

	{
		// Test the maximum string size
		// Setup
		String s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		assert(s == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
		assert(s.getLength() == 132);
		assert(s[0] == 'a');
		assert(s.isClosed());
	}

	{
		String s("blah", 2);
		assert(s == "blah");
		assert(s.isClosed());
		assert(s.getLength() == 4);
	}

	std::cout << "Completed testing string's C-Style string constructor." << std::endl;

	return 0;
}
