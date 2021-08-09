#ifndef PHONE_NUMBER_TESTS_H
#define PHONE_NUMBER_TESTS_H

#include "../basetest.h"
#include "phonenumber.h"

class PhoneNumberTest : public BaseTest<std::string, PhoneNumber>
{
private:
    inline static const std::string _classUnderTest{"[PhoneNumberTest]"};
    inline static const std::vector<std::string> VALID_VALUES{"(11)-123456789", "(44)-001133559", "(89)-945678131"};
    inline static const std::vector<std::string> INVALID_VALUES{"(10)-123456789", "(44)-12345678", "(89)-0123456789", "(11)-000000000"};

public:
    PhoneNumberTest() : BaseTest<std::string, PhoneNumber>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
    {
    }
};

#endif