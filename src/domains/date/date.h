#ifndef DATE_H
#define DATE_H

#include "../basedomain.h"

class Date : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string value);
    bool _isValidDate(std::string date);
    bool _isLeapYear(unsigned int year);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^(0[0-9]|1[0-9]|2[0-9]|3[01])/(0[1-9]|1[0-2])/([2-9][0-9]{3})$")};
    static constexpr std::array<unsigned int, 13> DAYS_PER_MONTH{0, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};

    unsigned int _day;
    unsigned int _month;
    unsigned int _year;

public:
    Date() {}

    Date(std::string date)
    {
        set(date);
    }

    unsigned int getDay()
    {
        return _day;
    }

    unsigned int getMonth()
    {
        return _month;
    }

    unsigned int getYear()
    {
        return _year;
    }

    void set(std::string date) override;
};

#endif