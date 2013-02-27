// bigint Test Program
//
// Tests:  times_10, uses ==
//

#include "bigint.h"

#include <cassert>

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi.times_single_digit(1);  //Or whatever you call it.

        // Verify
        assert(bi == 3);
    }

	{
		bigint bi(5);
		bi.times_single_digit(3);
		assert(bi == 15);
	}

	{
		bigint bi(10);
		bi.times_single_digit(0);
		assert(bi == 0);
	}

	{
		bigint bi(43);
		bi.times_single_digit(9);
		assert(bi == 387);
	}

	{
		bigint bi(10000);
		bi.times_single_digit(5);
		assert(bi == 50000);
	}

    std::cout << "Done testing bigint * single digit" << std::endl;
}
