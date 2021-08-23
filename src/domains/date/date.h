#ifndef DATE_H
#define DATE_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Representation of theater session date.
///
/// Format rules:
///
/// - Days between 01 and 31.
///
/// - Months between 01 and 12.
///
/// - Years between 2000 and 9999
///
/// - Following the date format DD/MM/YYYY
///

class Date : public BaseDomain<std::string>
{
protected:
    ///
    /// Returns true if the value follows the date format, and returns false otherwise.
    ///
    /// @param value
    ///

    bool _isRightPattern(std::string value);

    ///
    /// Returns true if the quantity of days is less than the maximum of days of each month, and returns false otherwise.
    ///
    /// @param date
    ///

    bool _isValidDate(std::string date);

    ///
    /// Returns true if the given year is a leap year, false otherwise.
    ///
    /// @param year
    ///

    bool _isLeapYear(unsigned int year);

    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^(0[1-9]|1[0-9]|2[0-9]|3[01])/(0[1-9]|1[0-2])/([2-9][0-9]{3})$")};
    inline static constexpr std::array<unsigned int, 13> DAYS_PER_MONTH{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    unsigned int _day;
    unsigned int _month;
    unsigned int _year;

public:
    ///
    /// Creates an instance of the class Date.
    ///

    Date() {}

    ///
    /// Initializes the object with a date if its value is valid.
    ///
    /// @param date
    ///

    Date(std::string date)
    {
        set(date);
    }

    ///
    /// Returns the the stored value of day.
    ///
    /// @return _day
    ///

    unsigned int getDay()
    {
        return _day;
    }

    ///
    /// Returns the stored value of month.
    ///
    /// @return _month
    ///

    unsigned int getMonth()
    {
        return _month;
    }

    ///
    /// Returns the stored value of year.
    ///
    /// @return _year
    ///
    unsigned int getYear()
    {
        return _year;
    }

    void set(std::string date) override;
};

#endif
