#include "time.h"

void Time::_validate(const std::string &time)
{
    if (!_isRightPattern(time))
    {
        throw std::invalid_argument("Invalid time '" + time + "'.");
    }
}

bool Time::_isRightPattern(const std::string &time)
{
    return std::regex_match(time, VALID_PATTERN);
}