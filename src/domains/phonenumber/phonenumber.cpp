#include "phonenumber.h"

bool PhoneNumber::_isRightPattern(std::string number)
{
    return std::regex_match(number, VALID_PATTERN);
}

bool PhoneNumber::_isValidAreacode(std::string number)
{
    int code = std::stoi(number.substr(1, 2).c_str());

    return (std::find(VALID_AREA_CODES.begin(), VALID_AREA_CODES.end(), code) != VALID_AREA_CODES.end());
}
bool PhoneNumber::_isPhoneNumberZeroes(std::string number)
{
    int phone = std::stoi(number.substr(5, 9).c_str());

    return (phone == 0);
}

void PhoneNumber::_validate(std::string number)
{
    if (!_isRightPattern(number))
    {
        throw std::invalid_argument("Invalid number pattern '" + number + "'.");
    }

    if (_isPhoneNumberZeroes(number))
    {
        throw std::invalid_argument("Invalid number '" + number + "'. It is only zeroes.");
    }

    if (!_isValidAreacode(number))
    {
        throw std::invalid_argument("Invalid area code '" + number.substr(1, 2) + "'.");
    }
}

void PhoneNumber::set(std::string number)
{
    _validate(number);

    _value = number;

    _areaCode = std::stoi(number.substr(1, 2).c_str());
    _number = std::stoi(number.substr(5, 9).c_str());
}
