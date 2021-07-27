#ifndef ROLE_H
#define ROLE_H

#include "../basedomain.h"

class Role : public BaseDomain<std::string>
{
protected:
    bool _isValidRole(std::string testedValue);
    void _validate(std::string testedValue) override;

    inline static const std::array<std::string, 6> VALID_VALUES{"Actor", "Cenographist", "Figurinist",
                                                                "Makeup Artist", "Sound Designer", "Lighting Designer"};

public:
    Role() {}

    Role(std::string role)
    {
        set(role);
    }
};

#endif