#ifndef BASEDOMAIN_H
#define BASEDOMAIN_H

#include <iostream>
#include <algorithm>
#include <cstdint>
#include <array>
#include <regex>

///
/// This is a base class that all the domain classes inherit from.
///

template <typename T>
class BaseDomain
{
protected:
    T _value;
    virtual void _validate(const T &testedValue) = 0;

public:
    BaseDomain() = default;
    virtual ~BaseDomain() {}

    ///
    /// Returns the stored value.
    ///
    /// @return _value
    ///

    T get() const
    {
        return _value;
    }

    ///
    /// Verifies if value is valid, and stores it if it is valid.
    ///
    /// @param value
    ///

    virtual void set(const T &value)
    {
        _validate(value);

        _value = value;
    }

    bool operator==(const BaseDomain &rhs)
    {
        return _value == rhs.get();
    }

    bool operator!=(const BaseDomain &rhs)
    {
        return _value != rhs.get();
    }

    bool operator==(const T &rhs)
    {
        return _value == rhs;
    }

    bool operator!=(const T &rhs)
    {
        return _value != rhs;
    }
};

#endif
