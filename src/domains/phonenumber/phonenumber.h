#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include "../basedomain.h"

class PhoneNumber : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string number);
    bool _isValidAreacode(std::string number);
    bool _isPhoneNumberZeroes(std::string number);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^\\([0-9]{2}\\)-[0-9]{9}$")};
    inline static constexpr std::array<uint8_t, 66> VALID_AREA_CODES{11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33,
                                                              34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68,
                                                              69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99};

    unsigned int _areaCode;
    unsigned int _number;

public:
    PhoneNumber() {}

    PhoneNumber(std::string number)
    {
        set(number);
    }

    unsigned int getAreaCode()
    {
        return _areaCode;
    }

    unsigned int getNumber()
    {
        return _number;
    }

    void set(std::string number) override;
};

#endif
