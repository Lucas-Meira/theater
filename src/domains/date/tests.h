#ifndef DATE_TESTS_H
#define DATE_TESTS_H

#include "../basetest.h"
#include "date.h"

namespace DateTest
{
    class UnitTest : public BaseTest<std::string, Date>
    {
    private:
        inline static const std::string _classUnderTest{"[DateTest]"};
        inline static const std::vector<std::string> VALID_VALUES{"10/01/2000", "30/12/9999", "29/02/2020", "31/07/5000", "01/01/9001"};
        inline static const std::vector<std::string> INVALID_VALUES{"29/02/2021", "32/01/2000", "9/12/2500", "25/13/2000", "00/10/2000", "01/01/10000", "01/01/1999"};

    public:
        UnitTest() : BaseTest<std::string, Date>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
        {
        }
    };
}

#endif