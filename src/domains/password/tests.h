#ifndef PASSWORD_TESTS_H
#define PASSWORD_TESTS_H

#include "password.h"
#include "../state.h"

namespace PasswordTest
{
    class UnitTest
    {
    private:
        Password *password;

        inline static const std::array<std::string, 5> VALID_VALUES{"AbC123!@", "DEf1#$97", "g597%&AG", "AbCdEF9!", "123456A@"};
        inline static const std::array<std::string, 8> INVALID_VALUES{"ABC123!", "ABC123!@#", "aab123!@", "abcdef12", "abcDef!@", "123456!@", "abc11d!@", "abc123!!"};

        State _state;

        void _setUp();
        void _tearDown();
        bool _testSuccessScenario();
        bool _testFailureScenario();
        void _printTestStatusMessage(std::string testName, bool passed);

    public:
        State run();
    };
}

#endif