#ifndef NAME_H
#define NAME_H

#include "../basedomain.h"

class Name : public BaseDomain<std::string>
{
private:
    bool _isFirstLetterCapitalized(std::string name);
    bool _containsSpaceSequence(std::string name);
    bool _isPeriodPrecededByLetter(std::string name);
    bool _containsOnlyValidCharacters(std::string name);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_CHARACTERS{std::regex("^[a-zA-Z. ]{5,20}$")};

public:
    Name() {}

    Name(std::string name)
    {
        set(name);
    }
};

#endif