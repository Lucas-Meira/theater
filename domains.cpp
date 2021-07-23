#include "domains.h"
#include <iostream>

void Capacity::_validate(uint16_t testedValue)
{
    bool isValid = false;

    for (const uint16_t &validValue : VALID_VALUES)
    {
        if (testedValue == validValue)
        {
            return;
        }
    }

    throw std::invalid_argument("Invalid value '" + std::to_string(testedValue) + "'.");
}

void Role::_validate(std::string testedValue)
{
    bool isValid = false;

    for (const std::string &validValue : VALID_VALUES)
    {
        if (testedValue == validValue)
        {
            return;
        }
    }

    throw std::invalid_argument("Invalid value '" + testedValue + "'.");
}

void IdCode::_validate(std::string testedValue)
{
    if (!_isRightPattern(testedValue))
    {
        throw std::invalid_argument("Invalid value '" + testedValue + "'.");
    }
}

bool IdCode::_isRightPattern(std::string testedValue)
{
    return std::regex_match(testedValue, VALID_PATTERN);
}

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

    if (_month != 2 || !_isLeapYear(year))
    {
        if (day > DAYS_PER_MONTH[month])
        {
            return false;
        }
    }
    else
    {
        if (day > DAYS_PER_MONTH[month] + 1)
        {
            return false;
        }
    }

    _day = day;
    _month = month;
    _year = year;

    return true;
}

bool Date::_isLeapYear(unsigned int year)
{
    if (!(year % 4) and (year % 100) || !(year % 400))
    {
        return true;
    }

    return false;
}

void Email::set(std::string address)
{
    _validate(address);

    _value = address;

    std::smatch matches;
    std::regex_search(address, matches, VALID_PATTERN);

    _local = matches[1];
    _domain = matches[2];
}

void Email::_validate(std::string testedAddress)
{
    if (!_isRightPattern(testedAddress) or !_isValidPeriods(testedAddress))
    {
        throw std::invalid_argument("Invalid address '" + testedAddress + "'.");
    }
}

bool Email::_isRightPattern(std::string testedAddress)
{
    return std::regex_match(testedAddress, VALID_PATTERN);
}

bool Email::_isValidPeriods(std::string testedAddress)
{
    return !_isPeriodSequence(testedAddress) and !_isPeriodAtBeginningOrEnd(testedAddress);
}

bool Email::_isPeriodSequence(std::string testedAddress)
{
    return std::regex_search(testedAddress, std::regex("\\.{2,}"));
}

bool Email::_isPeriodAtBeginningOrEnd(std::string testedAddress)
{
    std::smatch matches;
    std::regex_search(testedAddress, matches, VALID_PATTERN);

    std::string local = matches[1];
    std::string domain = matches[2];

    if (local.front() == '.' or local.back() == '.' or
        domain.front() == '.' or domain.back() == '.')
    {
        return true;
    }

    return false;
}

void Time::_validate(std::string time)
{
    if (!_isRightPattern(time))
    {
        throw std::invalid_argument("Invalid time '" + time + "'.");
    }
}

bool Time::_isRightPattern(std::string time)
{
    return std::regex_match(time, VALID_PATTERN);
}