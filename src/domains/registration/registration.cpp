#include "registration.h"

void Registration::_validate(const std::string &registration)
{
    if (!_isRightPattern(registration))
    {
        throw std::invalid_argument("Invalid registration '" + registration + "'.");
    }
}

bool Registration::_isRightPattern(const std::string &registration)
{
    return std::regex_match(registration, VALID_PATTERN);
}
