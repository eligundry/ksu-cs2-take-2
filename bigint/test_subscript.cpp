// bigint Test Program
//
// Tests:  subscript, uses ==
//

#include "bigint.h"
#include <cassert>

//===========================================================================
int main ()
{
	{
		bigint bi(1);
		assert(bi[0] == 1);
	}

    {
        // Setup
        bigint bi(4);

        // Test
        int digit = bi[0];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);
    }

	{
		// Setup
		bigint bi(1234);

		// Test & Verify
		assert(bi[0] == 4);
		assert(bi[1] == 3);
		assert(bi[2] == 2);
		assert(bi[3] == 1);
	}

    std::cout << "Done testing subscript." << std::endl;
}

