#include "role.h"

bool Role::_isValidRole(std::string testedValue)
{
    return (std::find(VALID_VALUES.begin(), VALID_VALUES.end(), testedValue) != VALID_VALUES.end());
}

void Role::_validate(std::string testedValue)
{
    if (!_isValidRole(testedValue))
    {
        throw std::invalid_argument("Invalid role '" + testedValue + "'.");
    }
}