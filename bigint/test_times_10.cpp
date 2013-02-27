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
        bi.times10(0); //Or whatever you call it.

        // Verify
        assert(bi == 3);
    }

	{
		bigint bi(10);
		bi.times10(1);
		assert(bi == 100);
	}

	{
		bigint bi(10);
		bi.times10(2);
		assert(bi == 1000);
	}

	{
		bigint bi(33);
		bi.times10(50);
		assert(bi == bigint("3300000000000000000000000000000000000000000000000000"));
	}

    std::cout << "Done testing times10" << std::endl;
}

