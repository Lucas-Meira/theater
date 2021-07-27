#ifndef IDCODE_TESTS_H
#define IDCODE_TESTS_H

#include "../basetest.h"
#include "idcode.h"

namespace IdCodeTest
{
    class UnitTest : public BaseTest<std::string, IdCode>
    {
    private:
        inline static const std::string _classUnderTest{"[IdCodeTest]"};
        inline static const std::vector<std::string> VALID_VALUES{"AA0000", "AZ9999", "DF1234", "WE5849", "OL1313"};
        inline static const std::vector<std::string> INVALID_VALUES{"ABC012", "A01234", "ABCDEF", "123456", "A12345", "1A3425", "0123AB"};

    public:
        UnitTest() : BaseTest<std::string, IdCode>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
        {
        }
    };
}

#endif