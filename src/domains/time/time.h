#ifndef TIME_H
#define TIME_H

#include "../basedomain.h"

class Time : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string time);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^([01][0-9]|2[0-3]):(00|15|30|45)$")};

    unsigned int _hours;
    unsigned int _minutes;

public:
    Time() {}

    Time(std::string time)
    {
        set(time);
    }

    unsigned int getHours()
    {
        return _hours;
    }

    unsigned int getMinutes()
    {
        return _minutes;
    }
};

#endif