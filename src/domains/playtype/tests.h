#ifndef PLAY_TYPE_TESTS_H
#define PLAY_TYPE_TESTS_H

#include "../basetest.h"
#include "playtype.h"

class PlayTypeTest : public DomainBaseTest<std::string, PlayType>
{
private:
    inline static const std::string _classUnderTest{"[PlayTypeTest]"};

    inline static const std::vector<std::string> VALID_VALUES{"Auto", "Comedy", "Drama", "Farce", "Melodrama",
                                                              "Monologue", "Musical", "Opera", "Revue"};
    inline static const std::vector<std::string> INVALID_VALUES{"Rock", "Metal", "Jazz", "Blues", "auto",
                                                                "comedy", "musical"};

public:
    PlayTypeTest() : DomainBaseTest<std::string, PlayType>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
    {
    }
};

#endif