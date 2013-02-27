/*
 * =====================================================================================
 *
 *       Filename:  test_strip_nl.cpp
 *
 *    Description:  Tests strings strip_nl function
 *
 *        Version:  1.0
 *        Created:  02/25/2013 09:00:47 PM
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
		String test = "BALAH BLAHAH BLAHAH\nBLAHAHLAH BLAHH";
		assert(test.strip_nl() == "BALAH BLAHAH BLAHAHBLAHAHLAH BLAHH");
	}

	{
		String test = "\n\n";
		assert(test.strip_nl() == "");
	}

	std::cout << "Complted testing string's strip_nl function!" << std::endl;

	return 0;
}
