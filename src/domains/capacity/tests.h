#ifndef CAPACITY_TESTS_H
#define CAPACITY_TESTS_H

#include "capacity.h"
#include "../state.h"

namespace CapacityTest
{
    class UnitTest
    {
    private:
        Capacity *capacity;

        static constexpr std::array<uint16_t, 5> VALID_VALUES{100, 200, 300, 400, 500};
        static constexpr std::array<uint16_t, 5> INVALID_VALUES{0, 50, 250, 600, 1200};

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