#ifndef BASETEST_E_H_INCLUDED
#define BASETEST_E_H_INCLUDED

#include <vector>
#include <iostream>

#include "../state.h"
template <class C>
class EntityBaseTest
{
protected:
    C *object;
    State _state;
    std::string _classUnderTest;

    void _setUp();

    void _tearDown();

    virtual void _testSuccessScenario() = 0;
    virtual void _testFailureScenario() = 0;

    void _printTestStatusMessage();

public:

    EntityBaseTest(std::string classUnderTest) : _classUnderTest(classUnderTest)

    {
    }

    State run();
};

template < class C>
void EntityBaseTest< C> :: _setUp()
{
        object = new C();

        _state.set(true);
    }

template <class C>
void EntityBaseTest< C>::_tearDown()
 {
        delete object;
    }

template < class C>
void EntityBaseTest< C>::_printTestStatusMessage()
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

template <class C>
State EntityBaseTest< C>::run()
{
    std::cout << _classUnderTest << " [ RUN      ]" << std::endl;

    _setUp();

    _testSuccessScenario();
    _testFailureScenario();

    _tearDown();

    _printTestStatusMessage();

    std::cout << _classUnderTest << " [     DONE ]" << std::endl;

    return _state;
}

#endif
