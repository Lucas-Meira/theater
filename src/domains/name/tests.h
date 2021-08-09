#ifndef NAME_TESTS_H
#define NAME_TESTS_H

#include "../basetest.h"
#include "name.h"

class NameTest : public BaseTest<std::string, Name>
{
private:
    inline static const std::string _classUnderTest{"[NameTest]"};
    inline static const std::vector<std::string> VALID_VALUES{"Joohn", "John Doe", "Mr. John Doe", "Sr. John Doe", "Mr. John Doe LongNam"};
    inline static const std::vector<std::string> INVALID_VALUES{"John", "Mr. John Doe LongName", ".John", "Mr. John doe", "John  Doe", "John . Doe"};

public:
    NameTest() : BaseTest<std::string, Name>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
    {
    }
};

#endif