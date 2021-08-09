#ifndef PASSWORD_TESTS_H
#define PASSWORD_TESTS_H

#include "../../basetest.h"
#include "password.h"

namespace PasswordTest
{
    class UnitTest : public BaseTest<std::string, Password>
    {
    private:
        inline static const std::string _classUnderTest{"[PasswordTest]"};
        inline static const std::vector<std::string> VALID_VALUES{"AbC123!@", "DEf1#$97", "g597%&AG", "AbCdEF9!", "123456A@"};
        inline static const std::vector<std::string> INVALID_VALUES{"ABC123!", "ABC123!@#", "aab123!@", "abcdef12", "abcDef!@", "123456!@", "abc11d!@", "abc123!!"};

    public:
        UnitTest() : BaseTest<std::string, Password>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
        {
        }
    };
}

#endif