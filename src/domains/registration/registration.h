#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Representation of the participant registration.
///
/// Format rules:
/// - Must have 5 digits between 0 and 9.
/// - Can not have more than 1 of the same digit.
///

class Registration : public BaseDomain<std::string>
{
protected:
    ///
    /// Returns true if the value follows the format rules, and returns false otherwise.
    ///
    /// @param registration
    ///

    bool _isRightPattern(const std::string &registration);

    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(const std::string &testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^(?!.*(.).*\\1)\\d{5}$")};

public:
    ///
    /// Initializes an instance of class Registration.
    ///

    Registration() {}

    ///
    /// Initializes the object with a registration if its value is valid.
    ///
    /// @param registration
    ///

    Registration(const std::string &registration)
    {
        set(registration);
    }
};

#endif
