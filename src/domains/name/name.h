#ifndef NAME_H
#define NAME_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Name is the identifying name of each participant.
///
/// Format rules:
/// - Each character is a letter (capitalized or not), a period or a empty space.
/// - Name have the minimum of 5 characters and the maximum of 20 characters.
/// - The first character is a capitalized letter.
/// - More than one space between letters is not allowed.
/// - Period have to be preceded by a letter.
///

class Name : public BaseDomain<std::string>
{
private:
    ///
    /// Returns false if the first letter of each word in name is not capitalized, and returns true otherwise.
    ///
    /// @param name
    ///

    bool _isFirstLetterCapitalized(const std::string &name);

    ///
    /// Returns true if the name have more than an empty space in sequence, and returns true otherwise.
    ///
    /// @param name
    ///

    bool _containsSpaceSequence(const std::string &name);

    ///
    /// Returns false if the first letter is a period or the character preceding the period is not a letter, and returns true otherwise.
    ///
    /// @param name
    ///

    bool _isPeriodPrecededByLetter(const std::string &name);

    ///
    /// Returns true if name have nothing else but letters, empty spaces or periods. Returns false otherwise.
    ///
    /// @param name
    ///

    bool _containsOnlyValidCharacters(const std::string &name);

    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(const std::string &testedValue) override;

    inline static const std::regex VALID_CHARACTERS{std::regex("^[a-zA-Z. ]{5,20}$")};

public:
    ///
    /// Creates an instance of the class Name.
    ///

    Name() {}

    ///
    /// Initializes the object with a name if its value is valid.
    ///
    /// @param name
    ///

    Name(const std::string &name)
    {
        set(name);
    }
};

#endif
