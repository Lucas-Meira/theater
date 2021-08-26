#ifndef PLAY_TEST_H
#define PLAY_TEST_H

#include "../basetest.h"
#include "play.h"
#include "../../state.h"

class PlayTest : public EntityBaseTest<Play>
{
private:
    inline static const std::string _classUnderTest{"[PlayTest]"};

    inline static const IdCode validId{"AA0000"};
    inline static const Name validName{"The Phantom Ot Opera"};
    inline static const PlayType validType{"Musical"};
    inline static const Rating validRating{"12"};

    inline static const std::string invalidId{"ABC012"};
    inline static const std::string invalidName{"The Phantom of the Opera"};
    inline static const std::string invalidType{"Rock"};
    inline static const std::string invalidRating{"11"};

    void _testSuccessScenario();
    void _testFailureScenario();

public:
    PlayTest() : EntityBaseTest<Play>(_classUnderTest)
    {
    }
};

void PlayTest::_testSuccessScenario()
{
    object->setId(validId);

    if (object->getId() != validId)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getId().get() + "', expected '" + validId.get() + +"'.");
    }

    object->setName(validName);

    if (object->getName() != validName)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getName().get() + "', expected '" + validName.get() + "'.");
    }

    object->setType(validType);

    if (object->getType() != validType)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getType().get() + "', expected '" + validType.get() + "'.");
    }

    object->setRating(validRating);

    if (object->getRating() != validRating)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + object->getRating().get() + "', expected '" + validRating.get() + "'.");
    }
}

void PlayTest::_testFailureScenario()
{
    try
    {
        object->setId(invalidId);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getId() == invalidId)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getId().get() + "', expected nothing.");
        }
    }

    try
    {
        object->setName(invalidName);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getName() == invalidName)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getName().get() + "', expected nothing.");
        }
    }

    try
    {
        object->setType(invalidType);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getType() == invalidType)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getType().get() + "', expected nothing.");
        }
    }

    try
    {
        object->setRating(invalidRating);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getRating() == invalidRating)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + object->getRating().get() + "', expected nothing.'");
        }
    }
}
#endif
