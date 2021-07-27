#ifndef IMMATRICULATION_TESTS_H
#define IMMATRICULATION_TESTS_H

#include "../basetest.h"
#include "immatriculation.h"

namespace ImmatriculationTest
{
    class UnitTest : public BaseTest<std::string, Immatriculation>
    {
    private:
        inline static const std::string _classUnderTest{"[ImmatriculationTest]"};
        inline static const std::vector<std::string> VALID_VALUES{"01234", "12345", "97864", "15837", "97356"};
        inline static const std::vector<std::string> INVALID_VALUES{"0123", "012345", "A1234", "22456", "97849"};

    public:
        UnitTest() : BaseTest<std::string, Immatriculation>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
        {
        }
    };
}

#endif