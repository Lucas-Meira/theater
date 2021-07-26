#ifndef IDCODE_TESTS_H
#define IDCODE_TESTS_H

#include "idcode.h"
#include "../state.h"

namespace IdCodeTest
{
    class UnitTest
    {
    private:
        IdCode *code;

        inline static const std::array<std::string, 5> VALID_VALUES{"AA0000", "AZ9999", "DF1234", "WE5849", "OL1313"};
        inline static const std::array<std::string, 7> INVALID_VALUES{"ABC012", "A01234", "ABCDEF", "123456", "A12345", "1A3425", "0123AB"};

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