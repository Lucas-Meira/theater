#ifndef EMAIL_H
#define EMAIL_H

#include "../basedomain.h"

class Email : public BaseDomain<std::string>
{
protected:
    void _validate(std::string testedValue) override;
    bool _isPeriodSequence(std::string testedAddress);
    bool _isPeriodAtBeginningOrEnd(std::string testedAddress);
    bool _isValidPeriods(std::string testedAddress);
    bool _isRightPattern(std::string testedAddress);
    inline static const std::regex VALID_PATTERN{std::regex("^([a-zA-Z0-9!#$%&'*+\\-/=?^_`{|}~.]{3,64})@([a-zA-Z0-9!#$%&'*+\\-/=?^_`{|}~.]{5,255})$")};

    std::string _local;
    std::string _domain;

public:
    Email() {}

    Email(std::string address)
    {
        set(address);
    }

    std::string getLocal() const { return _local; };
    std::string getDomain() const { return _domain; };

    void set(std::string address) override;
};

#endif