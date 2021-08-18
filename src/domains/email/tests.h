#ifndef EMAIL_TESTS_H
#define EMAIL_TESTS_H

#include "../basetest.h"
#include "email.h"

class EmailTest : public DomainBaseTest<std::string, Email>
{
private:
    inline static const std::string _classUnderTest{"[EmailTest]"};
    inline static const std::vector<std::string> VALID_VALUES{"valid.email123@gmail.com", "!#$%&'*+-/=?^_`{|}~characterTest.123@verylongemail.net"};
    inline static const std::vector<std::string> INVALID_VALUES{".email@email.com", "email.@email.com", "email@.email.com", "email@email.", "email..email@email.com", "a@email.com", "abcdef@em"};

public:
    EmailTest() : DomainBaseTest<std::string, Email>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
    {
    }
};

#endif