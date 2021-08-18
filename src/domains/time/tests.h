#ifndef TIME_TEST_H
#define TIME_TEST_H

#include "../basetest.h"
#include "time.h"

class TimeTest : public DomainBaseTest<std::string, Time>
{
private:
    inline static const std::string _classUnderTest{"[TimeTest]"};

    inline static const std::vector<std::string> VALID_VALUES{"00:15", "12:30", "23:45", "11:00"};
    inline static const std::vector<std::string> INVALID_VALUES{"24:00", "00:10", "9:45"};

public:
    TimeTest() : DomainBaseTest<std::string, Time>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
    {
    }
};

#endif