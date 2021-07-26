#ifndef IMMATRICULATION_TESTS_H
#define IMMATRICULATION_TESTS_H

#include "immatriculation.h"
#include "../state.h"

namespace ImmatriculationTest
{
    class UnitTest
    {
    private:
        Immatriculation *immatriculation;

        inline static const std::array<std::string, 5> VALID_VALUES{"01234", "12345", "97864", "15837", "97356"};
        inline static const std::array<std::string, 5> INVALID_VALUES{"0123", "012345", "A1234", "22456", "97849"};

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