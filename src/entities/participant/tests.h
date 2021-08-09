#ifndef PARTICIPANT_TEST_H
#define PARTICIPANT_TEST_H

#include "participant.h"
#include "../../state.h"

namespace ParticipantTest
{
    class UnitTest
    {
    private:
        Participant *participant;
        State _state;

        inline static const std::string _classUnderTest{"[ParticipantTest]"};

        inline static const Registration validRegistration{"97864"};
        inline static const Name validFirstName{"Mr. John"};
        inline static const Name validLastName{"Dupont"};
        inline static const Email validEmail{"john@example.com"};
        inline static const PhoneNumber validPhoneNumber{"(11)-123456789"};
        inline static const Password validPassword{"AbCdEF9!"};
        inline static const Role validRole{"Actor"};

        inline static const std::string invalidRegistration{"A1234"};
        inline static const std::string invalidFirstName{"John"};
        inline static const std::string invalidLastName{"Doe"};
        inline static const std::string invalidEmail{".john@example.com"};
        inline static const std::string invalidPhoneNumber{"(00)-123456789"};
        inline static const std::string invalidPassword{"AbCdEF9"};
        inline static const std::string invalidRole{"Driver"};

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
        participant = new Participant();

        _state.set(true);
    }

    void UnitTest::_tearDown()
    {
        delete participant;
    }

    void UnitTest::_testSuccessScenario()
    {
        participant->setRegistration(validRegistration);

        if (participant->getRegistration().get() != validRegistration.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + participant->getRegistration().get() + "', expected '" + validRegistration.get() + +"'.");
        }

        participant->setFirstName(validFirstName);

        if (participant->getFirstName().get() != validFirstName.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + participant->getFirstName().get() + "', expected '" + validFirstName.get() + "'.");
        }

        participant->setLastName(validLastName);

        if (participant->getLastName().get() != validLastName.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + participant->getLastName().get() + "', expected '" + validLastName.get() + "'.");
        }

        participant->setEmail(validEmail);

        if (participant->getEmail().get() != validEmail.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + participant->getEmail().get() + "', expected '" + validEmail.get() + "'.");
        }

        participant->setPhoneNumber(validPhoneNumber);

        if (participant->getPhoneNumber().get() != validPhoneNumber.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + participant->getPhoneNumber().get() + "', expected '" + validPhoneNumber.get() + "'.");
        }

        participant->setPassword(validPassword);

        if (participant->getPassword().get() != validPassword.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + participant->getPassword().get() + "', expected '" + validPassword.get() + "'.");
        }

        participant->setRole(validRole);

        if (participant->getRole().get() != validRole.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + participant->getRole().get() + "', expected '" + validRole.get() + "'.");
        }
    }

    void UnitTest::_testFailureScenario()
    {
        try
        {
            participant->setRegistration(invalidRegistration);
            _state.set(false);
        }
        catch (...)
        {
            if (participant->getRegistration().get() == invalidRegistration)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + participant->getRegistration().get() + "', expected nothing.");
            }
        }

        try
        {
            participant->setFirstName(invalidFirstName);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (participant->getFirstName().get() == invalidFirstName)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + participant->getFirstName().get() + "', expected nothing.");
            }
        }

        try
        {
            participant->setLastName(invalidLastName);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (participant->getLastName().get() == invalidLastName)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + participant->getLastName().get() + "', expected nothing.");
            }
        }

        try
        {
            participant->setEmail(invalidEmail);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (participant->getEmail().get() == invalidEmail)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + participant->getEmail().get() + "', expected nothing.'");
            }
        }

        try
        {
            participant->setPhoneNumber(invalidPhoneNumber);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (participant->getPhoneNumber().get() == invalidPhoneNumber)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + participant->getPhoneNumber().get() + "', expected nothing.");
            }
        }

        try
        {
            participant->setPassword(invalidPassword);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (participant->getPassword().get() == invalidPassword)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + participant->getPassword().get() + "', expected nothing.");
            }
        }

        try
        {
            participant->setRole(invalidRole);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (participant->getRole().get() == invalidRole)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + participant->getRole().get() + "', expected nothing.'");
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