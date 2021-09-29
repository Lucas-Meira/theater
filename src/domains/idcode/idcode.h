#ifndef IDCODE_H
#define IDCODE_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// IdCode is the identifying code of each participant
///
/// Format rules:
/// - Format LLNNNN
/// - Where each L is a capital letter between A and Z
/// - and each N is a digit between 0 and 9.
///

class IdCode : public BaseDomain<std::string>
{
protected:
    ///
    /// Returns true if the value follows the IdCode format, and returns false otherwise.
    ///
    /// @param value
    ///

    bool _isRightPattern(const std::string &value);

    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(const std::string &testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^[a-zA-Z]{2}[0-9]{4}$")};

public:
    ///
    /// Creates an instance of the class IdCode.
    ///

    IdCode() {}

    ///
    /// Initializes the object with a code if its value is valid.
    ///
    /// @param value
    ///

    IdCode(const std::string &value)
    {
        set(value);
    }
};

#endif
