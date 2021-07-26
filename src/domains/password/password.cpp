#include "password.h"

bool Password::_containsLetter(std::string password)
{
    return std::regex_search(password, std::regex("[a-zA-Z]"));
}

bool Password::_containsDigits(std::string password)
{
    return std::regex_search(password, std::regex("[0-9]"));
}

bool Password::_containsSpecialCharacters(std::string password)
{
    return std::regex_search(password, std::regex("[!@#$%&?]"));
}

bool Password::_isRightPattern(std::string password)
{
    return std::regex_match(password, VALID_CHARACTERS);
}

void Password::_validate(std::string password)
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
