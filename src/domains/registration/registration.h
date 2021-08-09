#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "../basedomain.h"

class Registration : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string registration);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^(?!.*(.).*\\1)\\d{5}$")};

public:
    Registration() {}

    Registration(std::string registration)
    {
        set(registration);
    }
};

#endif