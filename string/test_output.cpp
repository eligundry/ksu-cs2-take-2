/*
 * =====================================================================================
 *
 *       Filename:  test_output.cpp
 *
 *    Description:  Test's string's output functions
 *
 *        Version:  1.0
 *        Created:  02/24/2013 05:30:59 PM
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
		String str = "It's over 9000!";
		std::cout << str << std::endl;
	}

	std::cout << "Completed testing string's output function!" << std::endl;

	return 0;
}
