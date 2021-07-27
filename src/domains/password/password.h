#ifndef PASSWORD_H
#define PASSWORD_H

#include "../basedomain.h"

class Password : public BaseDomain<std::string>
{
private:
    bool _containsLetter(std::string password);
    bool _containsDigits(std::string password);
    bool _containsSpecialCharacters(std::string password);
    bool _isRightPattern(std::string password);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_CHARACTERS{std::regex("^(?!.*(.).*\\1)[a-zA-Z0-9!@#$%&?]{8}$")};

public:
    Password() {}

    Password(std::string password)
    {
        set(password);
    }
};

#endif