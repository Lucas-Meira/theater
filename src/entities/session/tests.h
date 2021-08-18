#ifndef SESSIONS_TEST_H
#define SESSIONS_TEST_H

#include "../basetest.h"
#include "session.h"
#include "../../state.h"

class SessionTest : public EntityBaseTest<Session>
{
private:
    inline static const std::string _classUnderTest{"[SessionTest]"};

    inline static const IdCode validId{"AA0000"};
    inline static const Date validDate{"10/01/2000"};
    inline static const Time validTime{"12:30"};

    inline static const std::string invalidId{"ABC012"};
    inline static const std::string invalidDate{"29/02/2021"};
    inline static const std::string invalidTime{"12:10"};

    void _testSuccessScenario();
    void _testFailureScenario();

public:
    SessionTest() : EntityBaseTest<Session>(_classUnderTest)
    {
    }
};

void SessionTest::_testSuccessScenario()
{
    object->setId(validId);

    if (object->getId().get() != validId.get())
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getId().get() + "', expected '" + validId.get() + +"'.");
    }

    object->setDate(validDate);

    if (object->getDate().get() != validDate.get())
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getDate().get() + "', expected '" + validDate.get() + "'.");
    }

    object->setTime(validTime);

    if (object->getTime().get() != validTime.get())
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getTime().get() + "', expected '" + validTime.get() + "'.");
    }
}

void SessionTest::_testFailureScenario()
{
    try
    {
        object->setId(invalidId);
        _state.set(false);
    }
    catch (...)
    {
        if (object->getId().get() == invalidId)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getId().get() + "', expected nothing.");
        }
    }

    try
    {
        object->setDate(invalidDate);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getDate().get() == invalidDate)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getDate().get() + "', expected nothing.");
        }
    }

    try
    {
        object->setTime(invalidTime);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getTime().get() == invalidTime)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getTime().get() + "', expected nothing.");
        }
    }
}

#endif
