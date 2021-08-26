#include "playtype.h"

bool PlayType::_isValidType(const std::string &type)
{
    return (std::find(VALID_VALUES.begin(), VALID_VALUES.end(), type) != VALID_VALUES.end());
}

void PlayType::_validate(const std::string &type)
{
    if (!_isValidType(type))
    {
        throw std::invalid_argument("Invalid play type '" + type + "'.");
    }
}