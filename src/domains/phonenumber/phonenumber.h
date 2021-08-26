#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Name is the identifying phone number of each participant.
///
/// Format rules:
/// - Following the format (XX)-YYYYYYYYY
/// - XX is exactly one of these numbers: 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33, 34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99
/// - Y is a number between 0 and 9
/// - (XX)-000000000 is not allowed.
///

class PhoneNumber : public BaseDomain<std::string>
{
protected:
    ///
    /// Returns false if it has any character out of the allowed characters, and returns true otherwise.
    ///
    /// @param number
    ///

    bool _isRightPattern(const std::string &number);

    ///
    /// Returns true if the part XX of the number is one of the allowed numbers, and returns false otherwise.
    ///
    /// @param number
    ///

    bool _isValidAreacode(const std::string &number);

    ///
    /// Returns true if the body of the number has just zeroes, and returns false otherwise.
    ///
    /// @param number
    ///

    bool _isPhoneNumberZeroes(const std::string &number);

    ///
    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(const std::string &testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^\\([0-9]{2}\\)-[0-9]{9}$")};
    inline static constexpr std::array<uint8_t, 66> VALID_AREA_CODES{11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33,
                                                                     34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54,
                                                                     55, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 73, 74, 75, 77, 79,
                                                                     81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99};

    unsigned int _areaCode;
    unsigned int _number;

public:
    ///
    /// Creates an instance of the class PhoneNumber.
    ///
    PhoneNumber() {}

    ///
    /// Initializes the object with a number if its value is valid.
    ///
    /// @param date
    ///

    PhoneNumber(const std::string &number)
    {
        set(number);
    }

    ///
    /// Returns the area code(XX)
    ///
    /// @return _areaCode
    ///

    unsigned int getAreaCode()
    {
        return _areaCode;
    }

    ///
    /// Returns the body of the number (YYYYYYYYY)
    ///
    /// @return _number
    ///

    unsigned int getNumber()
    {
        return _number;
    }

    void set(const std::string &number) override;
};

#endif
