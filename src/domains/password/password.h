#ifndef PASSWORD_H
#define PASSWORD_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Password is the password code of each participant.
///
/// Format rules:
///
/// - Exactly 8 characters.
///
/// - Which these characters can be letters between A and B (capitalized or not), digits between 0 and 9 or special characters. At least one of each.
///
/// - Special characters is ! @ $ % & ?
///
/// - Repeated characters are not allowed.
///

class Password : public BaseDomain<std::string>
{
private:
    ///
    /// Returns true if the password has at least one letter, and returns false otherwise.
    ///
    /// @param password
    ///

    bool _containsLetter(const std::string &password);

    ///
    /// Returns true if the password has at least one digit, and returns false otherwise.
    ///
    /// @param password
    ///

    bool _containsDigits(const std::string &password);

    ///
    /// Returns true if the password has at least one special character, and returns false otherwise.
    ///
    /// @param password
    ///

    bool _containsSpecialCharacters(const std::string &password);

    ///
    /// Verify if the password has no other character not allowed, returns false if it has and true otherwise.
    ///
    /// @param password
    ///

    bool _isRightPattern(const std::string &password);

    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(const std::string &testedValue) override;

    inline static const std::regex VALID_CHARACTERS{std::regex("^(?!.*(.).*\\1)[a-zA-Z0-9!@#$%&?]{8}$")};

public:
    ///
    /// Creates an instance of the class Password.
    ///

    Password() {}

    ///
    /// Initializes the object with a password if its value is valid.
    ///
    /// @param password
    ///

    Password(const std::string &password)
    {
        set(password);
    }
};

#endif
