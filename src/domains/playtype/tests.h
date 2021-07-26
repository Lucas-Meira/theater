#ifndef PLAY_TYPE_TESTS_H
#define PLAY_TYPE_TESTS_H

#include "playtype.h"
#include "../state.h"

namespace PlayTypeTest
{
    class UnitTest
    {
    private:
        PlayType *playType;

        inline static const std::array<std::string, 9> VALID_VALUES{"Auto", "Comedy", "Drama", "Farce", "Melodrama",
                                                                    "Monologue", "Musical", "Opera", "Revue"};
        inline static const std::array<std::string, 7> INVALID_VALUES{"Rock", "Metal", "Jazz", "Blues", "auto",
                                                                      "comedy", "musical"};

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