#ifndef EMAIL_H
#define EMAIL_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Email is the identifying email of each participant.
///
/// Format rules:
/// - Following the format body@domain.
/// - where the body part have no more than 64 characters.
/// - And the domain part have no more than 255 characters.
/// - Characters can be letters (capitalized or not), digits between 0 and 9 and Special characters.
/// - Special characters is ! # $ % & ' * + - / = ? ^ _ ` { | } ~ .
/// - Period can not be the first character or the last one, and can not have more than 1 in sequence.
///

class Email : public BaseDomain<std::string>
{
protected:
    ///
    /// Returns true if testedAddress have more than 1 period in sequence, and returns false otherwise.
    ///
    /// @param testedAddress
    ///

    bool _isPeriodSequence(std::string testedAddress);

    ///
    /// Returns true if testedAddress have period in the first character or in the last of each part of email, and returns false otherwise.
    ///
    /// @param testedAddress
    ///

    bool _isPeriodAtBeginningOrEnd(std::string testedAddress);

    ///
    /// Returns true if the periods follows the format rules, and returns false otherwise.
    ///
    /// @param testedAddress
    ///

    bool _isValidPeriods(std::string testedAddress);

    ///
    /// Returns true if testedAddress follows all the format rules, and returns false otherwise.
    ///
    /// @param testedAddress
    ///

    bool _isRightPattern(std::string testedAddress);

    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^([a-zA-Z0-9!#$%&'*+\\-/=?^_`{|}~.]{3,64})@([a-zA-Z0-9!#$%&'*+\\-/=?^_`{|}~.]{5,255})$")};

    std::string _local;
    std::string _domain;

public:
    ///
    /// Creates an instance of the class Email.
    ///

    Email() {}

    ///
    /// Initializes the object with a email if its value is valid.
    ///
    /// @param address
    ///

    Email(std::string address)
    {
        set(address);
    }

    ///
    /// Returns the the stored value of local.
    ///
    /// @return _local
    ///

    std::string getLocal() const { return _local; };

    ///
    /// Returns the the stored value of domain.
    ///
    /// @return _domain
    ///

    std::string getDomain() const { return _domain; };

    void set(std::string address) override;
};

#endif
