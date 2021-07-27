#include "immatriculation.h"

void Immatriculation::_validate(std::string immatriculation)
{
    if (!_isRightPattern(immatriculation))
    {
        throw std::invalid_argument("Invalid immatriculation '" + immatriculation + "'.");
    }
}

bool Immatriculation::_isRightPattern(std::string immatriculation)
{
    return std::regex_match(immatriculation, VALID_PATTERN);
}
