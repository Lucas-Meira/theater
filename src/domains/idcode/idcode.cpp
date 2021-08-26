#include "idcode.h"

void IdCode::_validate(const std::string &testedValue)
{
    if (!_isRightPattern(testedValue))
    {
        throw std::invalid_argument("Invalid value '" + testedValue + "'.");
    }
}

bool IdCode::_isRightPattern(const std::string &testedValue)
{
    return std::regex_match(testedValue, VALID_PATTERN);
}
