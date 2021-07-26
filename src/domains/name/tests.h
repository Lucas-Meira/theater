#ifndef NAME_TESTS_H
#define NAME_TESTS_H

#include "name.h"
#include "../state.h"

namespace NameTest
{
    class UnitTest
    {
    private:
        Name *name;

        inline static const std::array<std::string, 5> VALID_VALUES{"Joohn", "John Doe", "Mr. John Doe", "Sr. John Doe", "Mr. John Doe LongNam"};
        inline static const std::array<std::string, 6> INVALID_VALUES{"John", "Mr. John Doe LongName", ".John", "Mr. John doe", "John  Doe", "John . Doe"};

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