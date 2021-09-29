#include "name.h"

bool Name::_containsSpaceSequence(const std::string &name)
{
    return std::regex_search(name, std::regex("[\\ ]{2,}"));
}

bool Name::_isPeriodPrecededByLetter(const std::string &name)
{
    for (std::size_t i = 0; i < name.length(); i++)
    {
        if (name[i] == '.')
        {
            if (i == 0)
            {
                return false;
            }
            else if (!isalpha(name[i - 1]))
            {
                return false;
            }
        }
    }

    return true;
}

bool Name::_containsOnlyValidCharacters(const std::string &name)
{
    return std::regex_match(name, VALID_CHARACTERS);
}

bool Name::_isFirstLetterCapitalized(const std::string &name)
{
    std::istringstream ss(name);

    std::string word;
    while (ss.good())
    {
        ss >> word;

        if (!isupper(word.front()))
        {
            return false;
        }
    }

    return true;
}

void Name::_validate(const std::string &name)
{
    if (!_containsOnlyValidCharacters(name) or _containsSpaceSequence(name) or
        !_isPeriodPrecededByLetter(name) or !_isFirstLetterCapitalized(name))
    {
        throw std::invalid_argument("Invalid name '" + name + "'.");
    }
}
