#ifndef CAPACITY_H
#define CAPACITY_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Representation of the theater capacity.
///
/// Format rules:
/// - The value is valid if it is equal to 100, 200, 300, 400 or 500.
///

class Capacity : public BaseDomain<uint16_t>
{
protected:
    ///
    /// Returns true if the value follows the format rules, and returns false otherwise.
    ///
    /// @param testedValue
    ///

    bool _isValidCapacity(const uint16_t &testedValue);

    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(const uint16_t &testedValue) override;

    inline static constexpr std::array<const uint16_t, 5> VALID_VALUES{100, 200, 300, 400, 500};

public:
    ///
    /// Creates an instance of the class Capacity.
    ///

    Capacity() {}

    ///
    /// Initializes the object with a capacity if its value is valid.
    ///
    /// @param capacity
    ///

    Capacity(const uint16_t &capacity)
    {
        set(capacity);
    }
};

#endif
