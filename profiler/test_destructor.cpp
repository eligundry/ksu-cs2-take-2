/*
 * =====================================================================================
 *
 *       Filename:  test_destructor.cpp
 *
 *    Description:  Test ASTree's destructor
 *
 *        Version:  1.0
 *        Created:  04/16/2013 02:59:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include "ASTree.hpp"
#include <cassert>

int main()
{
	{
		ASTree blank_tree();
	}

	std::cout << "Completed testing ASTree's destructor!" << std::endl;

	return 0;
}
