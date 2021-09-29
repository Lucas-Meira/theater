#ifndef ROLE_H
#define ROLE_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Representation of the role of the each participant of the play.
///
/// Format rules:
/// - The value will be one of the following types: "Actor", "Cenographist", "Figurinist", "Makeup Artist", "Sound Designer", "Lighting Designer"
///

class Role : public BaseDomain<std::string>
{
protected:
    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    bool _isValidRole(const std::string &testedValue);

    ///
    /// Throw a exception if _isValidRole if false.
    ///
    /// @param testedValue
    ///

    void _validate(const std::string &testedValue) override;

    inline static const std::array<std::string, 6> VALID_VALUES{"Actor", "Cenographist", "Figurinist",
                                                                "Makeup Artist", "Sound Designer", "Lighting Designer"};

public:
    ///
    /// Initializes an instance of class Role.
    ///

    Role() {}

    ///
    /// Initializes the object with a role if its value is valid.
    ///
    /// @param role
    ///

    Role(const std::string &role)
    {
        set(role);
    }
};

#endif
