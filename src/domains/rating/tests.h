#ifndef RATING_TEST_H
#define RATING_TEST_H

#include "../basetest.h"
#include "rating.h"

namespace RatingTest
{
    class UnitTest : public BaseTest<std::string, Rating>
    {
    private:
        inline static const std::string _classUnderTest{"[RatingTest]"};

        inline static const std::vector<std::string> VALID_VALUES{"general", "10", "12", "14", "16", "18"};
        inline static const std::vector<std::string> INVALID_VALUES{"L", "11", "13", "5"};

    public:
        UnitTest() : BaseTest<std::string, Rating>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
        {
        }
    };
}

#endif