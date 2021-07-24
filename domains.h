#ifndef DOMAINS_H
#define DOMAINS_H

#include <cstdint>
#include <array>
#include <regex>

template <typename T>
class BaseDomain
{
protected:
    T _value;
    virtual void _validate(T testedValue) = 0;

public:
    inline T get() const
    {
        return _value;
    };

    virtual void set(T value)
    {
        _validate(value);

        _value = value;
    };
};

class Capacity : public BaseDomain<uint16_t>
{
protected:
    bool _isValidCapacity(uint16_t testedValue);
    void _validate(uint16_t testedValue) override;

    static constexpr std::array<const uint16_t, 5> VALID_VALUES{100, 200, 300, 400, 500};

public:
    Capacity() {}

    Capacity(uint16_t capacity)
    {
        set(capacity);
    }
};

class Role : public BaseDomain<std::string>
{
protected:
    bool _isValidRole(std::string testedValue);
    void _validate(std::string testedValue) override;

    inline static const std::array<std::string, 6> VALID_VALUES{"Actor", "Cenographist", "Figurinist",
                                                                "Makeup Artist", "Sound Designer", "Lighting Designer"};

public:
    Role() {}

    Role(std::string role)
    {
        set(role);
    }
};

class Rating : public BaseDomain<std::string>
{
protected:
    bool _isValidRating(std::string rating);
    void _validate(std::string testedValue) override;

    inline static const std::array<const std::string, 6> VALID_VALUES{"general", "10", "12", "14", "16", "18"};

public:
    Rating() {}

    Rating(std::string rating)
    {
        set(rating);
    }
};

class IdCode : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string value);
    void _validate(std::string testedValue) override;
    inline static const std::regex VALID_PATTERN{std::regex("^[a-zA-Z]{2}[0-9]{4}$")};

public:
    IdCode() {}

    IdCode(std::string value)
    {
        set(value);
    }
};

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

    inline unsigned int getDay()
    {
        return _day;
    }

    inline unsigned int getMonth()
    {
        return _month;
    }

    inline unsigned int getYear()
    {
        return _year;
    }

    void set(std::string date) override;
};

class Email : public BaseDomain<std::string>
{
protected:
    void _validate(std::string testedValue) override;
    bool _isPeriodSequence(std::string testedAddress);
    bool _isPeriodAtBeginningOrEnd(std::string testedAddress);
    bool _isValidPeriods(std::string testedAddress);
    bool _isRightPattern(std::string testedAddress);
    // TODO: CHECK MINIMUM NUMBER OF CHARACTERS
    inline static const std::regex VALID_PATTERN{std::regex("^([a-zA-Z0-9!#$%&'*+\\-/=?^_`{|}~.]{0,64})@([a-zA-Z0-9!#$%&'*+\\-/=?^_`{|}~.]{0,255})$")};

    std::string _local;
    std::string _domain;

public:
    Email() {}

    Email(std::string address)
    {
        set(address);
    }

    inline std::string getLocal() const { return _local; };
    inline std::string getDomain() const { return _domain; };

    void set(std::string address) override;
};

class Time : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string time);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^([01][09]|2[0-3]):(00|15|30|45)$")};

    unsigned int _hours;
    unsigned int _minutes;

public:
    Time() {}

    Time(std::string time)
    {
        set(time);
    }

    inline unsigned int getHours()
    {
        return _hours;
    }

    inline unsigned int getMinutes()
    {
        return _minutes;
    }
};

class Immatriculation : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string immatriculation);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^(?!.*(.).*\\1)\\d{5}$")};

public:
    Immatriculation() {}

    Immatriculation(std::string immatriculation)
    {
        set(immatriculation);
    }
};

class Password : public BaseDomain<std::string>
{
private:
    bool _containsLetter(std::string password);
    bool _containsDigits(std::string password);
    bool _containsSpecialCharacters(std::string password);
    bool _isRightPattern(std::string password);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_CHARACTERS{std::regex("^(?!.*(.).*\\1)[a-zA-Z0-9!@#$%&?]{8}$")};

public:
    Password() {}

    Password(std::string password)
    {
        set(password);
    }
};

class Name : public BaseDomain<std::string>
{
private:
    bool _isFirstLetterCapitalized(std::string name);
    bool _containsSpaceSequence(std::string name);
    bool _isPeriodPrecededByLetter(std::string name);
    bool _containsOnlyValidCharacters(std::string name);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_CHARACTERS{std::regex("^[a-zA-Z. ]{5,20}$")};

public:
    Name() {}

    Name(std::string name)
    {
        set(name);
    }
};

class PhoneNumber : public BaseDomain<std::string>
{
protected:
    bool _isRightPattern(std::string number);
    bool _isValidAreacode(std::string number);
    bool _isPhoneNumberZeroes(std::string number);
    void _validate(std::string testedValue) override;

    inline static const std::regex VALID_PATTERN{std::regex("^\\([0-9]{2}\\)-[0-9]{9}$")};
    static constexpr std::array<uint8_t, 66> VALID_AREA_CODES{11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33,
                                                              34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68,
                                                              69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99};

    unsigned int _areaCode;
    unsigned int _number;

public:
    PhoneNumber() {}

    PhoneNumber(std::string number)
    {
        set(number);
    }

    inline unsigned int getAreaCode()
    {
        return _areaCode;
    }

    inline unsigned int getNumber()
    {
        return _number;
    }

    void set(std::string number) override;
};

class PlayType : public BaseDomain<std::string>
{
protected:
    bool _isValidType(std::string type);
    void _validate(std::string testedValue) override;

public:
    PlayType() {}

    PlayType(std::string type)
    {
        set(type);
    }

    inline static const std::array<std::string, 9> VALID_VALUES{"Auto", "Comedy", "Drama", "Farce", "Melodrama",
                                                                "Monologue", "Musical", "Opera", "Revue"};
};

#endif
