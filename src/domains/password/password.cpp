#include "password.h"

bool Password::_containsLetter(const std::string &password)
{
    return std::regex_search(password, std::regex("[a-zA-Z]"));
}

bool Password::_containsDigits(const std::string &password)
{
    return std::regex_search(password, std::regex("[0-9]"));
}

bool Password::_containsSpecialCharacters(const std::string &password)
{
    return std::regex_search(password, std::regex("[!@#$%&?]"));
}

bool Password::_isRightPattern(const std::string &password)
{
    return std::regex_match(password, VALID_CHARACTERS);
}

void Password::_validate(const std::string &password)
{
    if (!_isRightPattern(password))
    {
        throw std::invalid_argument("Invalid password '" + password + "'.");
    }

    if (!_containsDigits(password) or !_containsSpecialCharacters(password) or !_containsLetter(password))
    {
        throw std::invalid_argument("Invalid password '" + password +
                                    "'. It doesn't contain necessary characters: letters, digits and at least one of the following ! @ # $ % & ?");
    }
}
