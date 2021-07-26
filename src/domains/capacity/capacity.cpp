#include "capacity.h"

bool Capacity::_isValidCapacity(uint16_t testedValue)
{
    return (std::find(VALID_VALUES.begin(), VALID_VALUES.end(), testedValue) != VALID_VALUES.end());
}

void Capacity::_validate(uint16_t testedValue)
{
    if (!_isValidCapacity(testedValue))
    {
        throw std::invalid_argument("Invalid capacity '" + std::to_string(testedValue) + "'.");
    }
}