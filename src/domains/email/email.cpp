#include "email.h"

void Email::set(const std::string &address)
{
    _validate(address);

    _value = address;

    std::smatch matches;
    std::regex_search(address, matches, VALID_PATTERN);

    _local = matches[1];
    _domain = matches[2];
}

void Email::_validate(const std::string &testedAddress)
{
    if (!_isRightPattern(testedAddress) or !_isValidPeriods(testedAddress))
    {
        throw std::invalid_argument("Invalid address '" + testedAddress + "'.");
    }
}

bool Email::_isRightPattern(const std::string &testedAddress)
{
    return std::regex_match(testedAddress, VALID_PATTERN);
}

bool Email::_isValidPeriods(const std::string &testedAddress)
{
    return !_isPeriodSequence(testedAddress) and !_isPeriodAtBeginningOrEnd(testedAddress);
}

bool Email::_isPeriodSequence(const std::string &testedAddress)
{
    return std::regex_search(testedAddress, std::regex("\\.{2,}"));
}

bool Email::_isPeriodAtBeginningOrEnd(const std::string &testedAddress)
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
