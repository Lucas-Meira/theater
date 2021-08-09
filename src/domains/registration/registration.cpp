#include "registration.h"

void Registration::_validate(std::string registration)
{
    if (!_isRightPattern(registration))
    {
        throw std::invalid_argument("Invalid registration '" + registration + "'.");
    }
}

bool Registration::_isRightPattern(std::string registration)
{
    return std::regex_match(registration, VALID_PATTERN);
}
