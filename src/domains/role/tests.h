#ifndef ROLE_TEST_H
#define ROLE_TEST_H

#include "../../basetest.h"
#include "role.h"

namespace RoleTest
{
    class UnitTest : public BaseTest<std::string, Role>
    {
    private:
        inline static const std::string _classUnderTest{"[RoleTest]"};

        inline static const std::vector<std::string> VALID_VALUES{"Actor", "Cenographist", "Figurinist",
                                                                  "Makeup Artist", "Sound Designer", "Lighting Designer"};
        inline static const std::vector<std::string> INVALID_VALUES{"actor", "musician", "", "Musician"};

    public:
        UnitTest() : BaseTest<std::string, Role>(_classUnderTest, VALID_VALUES, INVALID_VALUES)
        {
        }
    };
}

#endif