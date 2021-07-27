#ifndef CAPACITY_TESTS_H
#define CAPACITY_TESTS_H

#include "../basetest.h"
#include "capacity.h"

namespace CapacityTest
{
    class UnitTest : public BaseTest<uint16_t, Capacity>
    {
    private:
        inline static const std::string _classUnderTest{"[CapacityTest]"};
        inline static const std::vector<uint16_t> VALID_VALUES{100, 200, 300, 400, 500};
        inline static const std::vector<uint16_t> INVALID_VALUES{0, 50, 250, 600, 1200};

    public:
        UnitTest() : BaseTest<uint16_t, Capacity>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
        {
        }
    };
}

#endif