#ifndef IMMATRICULATION_H
#define IMMATRICULATION_H

#include "../basedomain.h"

class Immatriculation : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string immatriculation);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^(?!.*(.).*\\1)\\d{5}$")};

public:
    Immatriculation() {}

    Immatriculation(std::string immatriculation)
    {
        set(immatriculation);
    }
};

#endif