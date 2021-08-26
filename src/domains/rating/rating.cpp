#include "rating.h"

bool Rating::_isValidRating(const std::string &testedValue)
{
    return (std::find(VALID_VALUES.begin(), VALID_VALUES.end(), testedValue) != VALID_VALUES.end());
}

void Rating::_validate(const std::string &testedValue)
{
    if (!_isValidRating(testedValue))
    {
        throw std::invalid_argument("Invalid rating '" + testedValue + "'");
    }
}