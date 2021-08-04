#ifndef CAPACITY_H
#define CAPACITY_H

#include "../basedomain.h"

class Capacity : public BaseDomain<uint16_t>
{
protected:
    bool _isValidCapacity(uint16_t testedValue);
    void _validate(uint16_t testedValue) override;

    inline static constexpr std::array<const uint16_t, 5> VALID_VALUES{100, 200, 300, 400, 500};

public:
    Capacity() {}

    Capacity(uint16_t capacity)
    {
        set(capacity);
    }
};

#endif
