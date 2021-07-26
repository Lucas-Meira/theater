#ifndef DATE_TESTS_H
#define DATE_TESTS_H

#include "date.h"
#include "../state.h"

namespace DateTest
{
    class UnitTest
    {
    private:
        Date *date;

        inline static const std::array<std::string, 5> VALID_VALUES{"10/01/2000", "30/12/9999", "29/02/2020", "31/07/5000", "01/01/9001"};
        inline static const std::array<std::string, 7> INVALID_VALUES{"29/02/2021", "32/01/2000", "9/12/2500", "25/13/2000", "00/10/2000", "01/01/10000", "01/01/1999"};

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