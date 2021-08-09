#ifndef SESSIONS_TEST_H
#define SESSIONS_TEST_H

#include "session.h"
#include "../../state.h"

namespace SessionTest
{
    class UnitTest
    {
    private:
        Session *session;
        State _state;

        inline static const std::string _classUnderTest{"[SessionTest]"};

        inline static const IdCode validId{"AA0000"};
        inline static const Date validDate{"10/01/2000"};
        inline static const Time validTime{"12:30"};

        inline static const std::string invalidId{"ABC012"};
        inline static const std::string invalidDate{"29/02/2021"};
        inline static const std::string invalidTime{"12:10"};

        void _setUp();
        void _tearDown();
        void _testSuccessScenario();
        void _testFailureScenario();
        void _printTestStatusMessage();

    public:
        UnitTest()
        {
        }

        State run();
    };

    void UnitTest::_setUp()
    {
        session = new Session();

        _state.set(true);
    }

    void UnitTest::_tearDown()
    {
        delete session;
    }

    void UnitTest::_testSuccessScenario()
    {
        session->setId(validId);

        if (session->getId().get() != validId.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + session->getId().get() + "', expected '" + validId.get() + +"'.");
        }

        session->setDate(validDate);

        if (session->getDate().get() != validDate.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + session->getDate().get() + "', expected '" + validDate.get() + "'.");
        }

        session->setTime(validTime);

        if (session->getTime().get() != validTime.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + session->getTime().get() + "', expected '" + validTime.get() + "'.");
        }
    }

    void UnitTest::_testFailureScenario()
    {
        try
        {
            session->setId(invalidId);
            _state.set(false);
        }
        catch (...)
        {
            if (session->getId().get() == invalidId)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + session->getId().get() + "', expected nothing.");
            }
        }

        try
        {
            session->setDate(invalidDate);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (session->getDate().get() == invalidDate)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + session->getDate().get() + "', expected nothing.");
            }
        }

        try
        {
            session->setTime(invalidTime);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (session->getTime().get() == invalidTime)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + session->getTime().get() + "', expected nothing.");
            }
        }
    }

    void UnitTest::_printTestStatusMessage()
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

    State UnitTest::run()
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
}

#endif