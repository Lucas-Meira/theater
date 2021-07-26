#include "date.h"

void Date::_validate(std::string testedDate)
{
    if (!_isRightPattern(testedDate))
    {
        throw std::invalid_argument("Date " + testedDate + " doesn't match DD/MM/YYYY format.");
    }

    if (!_isValidDate(testedDate))
    {
        throw std::invalid_argument("Invalid date '" + testedDate + "'.");
    }
}

bool Date::_isRightPattern(std::string testedValue)
{
    return std::regex_match(testedValue, VALID_PATTERN);
}

bool Date::_isValidDate(std::string date)
{
    unsigned int day = std::stoi(date.substr(0, 2));
    unsigned int month = std::stoi(date.substr(3, 2));
    unsigned int year = std::stoi(date.substr(6, 4));

    if (month != 2 || !_isLeapYear(year))
    {
        if (day > DAYS_PER_MONTH[month])
        {
            return false;
        }
    }
    else if (day > DAYS_PER_MONTH[month] + 1)
    {
        return false;
    }

    return true;
}

bool Date::_isLeapYear(unsigned int year)
{
    if (((year % 4 == 0) and (year % 100 != 0)) || (year % 400 == 0))
    {
        return true;
    }

    return false;
}

void Date::set(std::string date)
{
    _validate(date);

    _value = date;

    _day = std::stoi(date.substr(0, 2));
    _month = std::stoi(date.substr(3, 2));
    _year = std::stoi(date.substr(6, 4));
}
