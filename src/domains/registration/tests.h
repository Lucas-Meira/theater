#ifndef REGISTRATION_TESTS_H
#define REGISTRATION_TESTS_H

#include "../basetest.h"
#include "registration.h"

class RegistrationTest : public BaseTest<std::string, Registration>
{
private:
    inline static const std::string _classUnderTest{"[RegistrationTest]"};
    inline static const std::vector<std::string> VALID_VALUES{"01234", "12345", "97864", "15837", "97356"};
    inline static const std::vector<std::string> INVALID_VALUES{"0123", "012345", "A1234", "22456", "97849"};

public:
    RegistrationTest() : BaseTest<std::string, Registration>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
    {
    }
};

#endif