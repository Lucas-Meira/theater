#ifndef PARTICIPANT_TEST_H
#define PARTICIPANT_TEST_H

#include "../basetest.h"
#include "participant.h"
#include "../../state.h"

class ParticipantTest : public EntityBaseTest<Participant>
{
private:
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

    void _testSuccessScenario();
    void _testFailureScenario();

public:
    ParticipantTest() : EntityBaseTest<Participant>(_classUnderTest)
    {
    }
};

void ParticipantTest::_testSuccessScenario()
{
    object->setRegistration(validRegistration);

    if (object->getRegistration() != validRegistration)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getRegistration().get() + "', expected '" + validRegistration.get() + +"'.");
    }

    object->setFirstName(validFirstName);

    if (object->getFirstName() != validFirstName)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getFirstName().get() + "', expected '" + validFirstName.get() + "'.");
    }

    object->setLastName(validLastName);

    if (object->getLastName() != validLastName)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getLastName().get() + "', expected '" + validLastName.get() + "'.");
    }

    object->setEmail(validEmail);

    if (object->getEmail() != validEmail)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getEmail().get() + "', expected '" + validEmail.get() + "'.");
    }

    object->setPhoneNumber(validPhoneNumber);

    if (object->getPhoneNumber() != validPhoneNumber)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getPhoneNumber().get() + "', expected '" + validPhoneNumber.get() + "'.");
    }

    object->setPassword(validPassword);

    if (object->getPassword() != validPassword)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getPassword().get() + "', expected '" + validPassword.get() + "'.");
    }

    object->setRole(validRole);

    if (object->getRole() != validRole)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getRole().get() + "', expected '" + validRole.get() + "'.");
    }
}

void ParticipantTest::_testFailureScenario()
{
    try
    {
        object->setRegistration(invalidRegistration);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getRegistration() == invalidRegistration)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getRegistration().get() + "', expected nothing.");
        }
    }

    try
    {
        object->setFirstName(invalidFirstName);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getFirstName() == invalidFirstName)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getFirstName().get() + "', expected nothing.");
        }
    }

    try
    {
        object->setLastName(invalidLastName);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getLastName() == invalidLastName)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getLastName().get() + "', expected nothing.");
        }
    }

    try
    {
        object->setEmail(invalidEmail);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getEmail() == invalidEmail)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getEmail().get() + "', expected nothing.'");
        }
    }

    try
    {
        object->setPhoneNumber(invalidPhoneNumber);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getPhoneNumber() == invalidPhoneNumber)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getPhoneNumber().get() + "', expected nothing.");
        }
    }

    try
    {
        object->setPassword(invalidPassword);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getPassword() == invalidPassword)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getPassword().get() + "', expected nothing.");
        }
    }

    try
    {
        object->setRole(invalidRole);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getRole() == invalidRole)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getRole().get() + "', expected nothing.'");
        }
    }
};

#endif
