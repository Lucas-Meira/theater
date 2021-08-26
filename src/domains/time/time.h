#ifndef TIME_H
#define TIME_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Representation of the time of the play in the theater.
///
/// Format rules:
/// - Following the time format HH:MM
/// - Where HH is an hour part, and the value must be between 00 and 23
/// - The MM is minute part, and the value must be 00, 15, 30 or 45
///

class Time : public BaseDomain<std::string>
{
protected:
    ///
    /// Returns true if the value follows the time format, and returns false otherwise.
    ///
    /// @param time
    ///

    bool _isRightPattern(const std::string &time);

    ///
    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(const std::string &testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^([01][0-9]|2[0-3]):(00|15|30|45)$")};

    unsigned int _hours;
    unsigned int _minutes;

public:
    ///
    /// Initializes an instance of class Time.
    ///

    Time() {}

    ///
    /// Initializes the object with a time if its value is valid.
    ///
    /// @param time
    ///

    Time(const std::string &time)
    {
        set(time);
    }

    ///
    /// Returns the the stored value of hour.
    ///
    /// @return _hours
    ///

    unsigned int getHours()
    {
        return _hours;
    }

    ///
    /// Returns the the stored value of minutes.
    ///
    /// @return _minutes
    ///

    unsigned int getMinutes()
    {
        return _minutes;
    }
};

#endif