// bigint Test Program
//
// Tests:  int constructor, uses ==
//

#include "bigint.h"

#include <cassert>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

	{
        //------------------------------------------------------
        // Setup fixture
		bigint left(0), right(1), result[3];

		// Test
		result[0] = left + right;
		result[1] = right + left;
		result[2] = right + right;

		// Verify
		assert(result[0] == 1);
		assert(result[1] == 1);
		assert(result[2] == 2);
	}

	{
        //------------------------------------------------------
        // Setup fixture
		bigint left(100), right(1000), result;

		// Test
		result = left + right;

		// Verify
		assert(result == 1100);
	}

	{
		bigint l(1), r(99), res;
		res = l + r;
		assert(res == 100);
	}

	{
		bigint l(598), r(1776), res;
		res = l + r;
		assert(res == 2374);
	}

	{
		bigint l = 598,
			   r = 1776,
			   res;

		res = l + r;
		assert(res == 2374);
	}

	{
		bigint l = 500,
			   r = 500,
			   res;

		res = l + r;
		assert(res == 1000);
	}

    std::cout << "Done with testing addition." << std::endl;
}

