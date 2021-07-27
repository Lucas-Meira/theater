#ifndef IDCODE_H
#define IDCODE_H

#include "../basedomain.h"

class IdCode : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string value);
    void _validate(std::string testedValue) override;
    inline static const std::regex VALID_PATTERN{std::regex("^[a-zA-Z]{2}[0-9]{4}$")};

public:
    IdCode() {}

    IdCode(std::string value)
    {
        set(value);
    }
};

#endif