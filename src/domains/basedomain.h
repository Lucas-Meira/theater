#ifndef BASEDOMAIN_H
#define BASEDOMAIN_H

#include <iostream>
#include <algorithm>
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
    BaseDomain() = default;
    virtual ~BaseDomain() {}

    T get() const
    {
        return _value;
    }

    virtual void set(T value)
    {
        _validate(value);

        _value = value;
    }
};

#endif