#ifndef PHONE_NUMBER_TESTS_H
#define PHONE_NUMBER_TESTS_H

#include "phonenumber.h"
#include "../state.h"

namespace PhoneNumberTest
{
    class UnitTest
    {
    private:
        PhoneNumber *phoneNumber;

        inline static const std::array<std::string, 3> VALID_VALUES{"(11)-123456789", "(44)-001133559", "(89)-945678131"};
        inline static const std::array<std::string, 4> INVALID_VALUES{"(10)-123456789", "(44)-12345678", "(89)-0123456789", "(11)-000000000"};

        State _state;

        void _setUp();
        void _tearDown();
        void _testSuccessScenario();
        void _testFailureScenario();
        void _printTestStatusMessage(std::string testName);

    public:
        State run();
    };
}

#endif