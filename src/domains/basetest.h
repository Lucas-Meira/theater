#ifndef BASETEST_H
#define BASETEST_H

#include <array>
#include <iostream>

#include "state.h"

template <typename T, class C>
class BaseTest
{
protected:
    C *object;
    State _state;
    std::string _classUnderTest;

    const std::vector<T> _validValues{};
    const std::vector<T> _invalidValues{};

    void _setUp();
    void _tearDown();
    void _testSuccessScenario();
    void _testFailureScenario();
    void _printTestStatusMessage();

public:
    BaseTest(std::string classUnderTest,
             const std::vector<T> &validValues,
             const std::vector<T> &invalidValues) : _classUnderTest(classUnderTest),
                                                    _validValues(validValues), _invalidValues(invalidValues)
    {
    }

    State run();
};

template <typename T, class C>
void BaseTest<T, C>::_setUp()
{
    object = new C();

    _state.set(true);
}

template <typename T, class C>
void BaseTest<T, C>::_tearDown()
{
    delete object;
}

template <typename T, class C>
void BaseTest<T, C>::_testSuccessScenario()
{
    for (const T &validValue : _validValues)
    {
        try
        {
            object->set(validValue);

            if (object->get() != validValue)
            {
                std::cout << "Expected: " << validValue << std::endl
                          << "Got: " << object->get() << std::endl;

                _state.set(false);
            }
        }
        catch (std::invalid_argument &exception)
        {
            std::cout << exception.what() << std::endl;

            _state.set(false);
        }
    }
}

template <typename T, class C>
void BaseTest<T, C>::_testFailureScenario()
{
    for (const T &invalidValue : _invalidValues)
    {
        try
        {
            object->set(invalidValue);

            std::cout << _classUnderTest << " Valid value '" << invalidValue << "'." << std::endl;

            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            continue;
        }
    }
}

template <typename T, class C>
void BaseTest<T, C>::_printTestStatusMessage()
{
    if (_state.get() == _state.SUCCESS)
    {
        std::cout << _classUnderTest << " \u001b[32m[  PASSED  ]\u001b[0m " << std::endl;
    }
    else
    {
        std::cout << _classUnderTest << " \u001b[31m[  FAILED  ]\u001b[0m " << std::endl;
    }
}

template <typename T, class C>
State BaseTest<T, C>::run()
{
    std::cout << _classUnderTest << " RUN" << std::endl;

    _setUp();
    _testSuccessScenario();
    _testFailureScenario();
    _tearDown();

    _printTestStatusMessage();

    std::cout << _classUnderTest << " DONE" << std::endl;

    return _state;
}

#endif