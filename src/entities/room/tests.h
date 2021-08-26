#ifndef ROOM_TEST_H
#define ROOM_TEST_H

#include "../basetest.h"
#include "room.h"
#include "../../state.h"

class RoomTest : public EntityBaseTest<Room>
{
private:
    inline static const std::string _classUnderTest{"[RoomTest]"};

    inline static const IdCode validId{"AA0000"};
    inline static const Name validName{"Villa Lobos"};
    inline static const Capacity validCapacity{100};

    inline static const std::string invalidId{"ABC012"};
    inline static const std::string invalidName{"Villa lobos"};
    inline static const uint16_t invalidCapacity{150};

    void _testSuccessScenario();
    void _testFailureScenario();

public:
    RoomTest() : EntityBaseTest<Room>(_classUnderTest)
    {
    }
};

void RoomTest::_testSuccessScenario()
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

    object->setCapacity(validCapacity);

    if (object->getCapacity() != validCapacity)
    {
        _state.set(false);
        throw std::invalid_argument("Got '" + std::to_string(object->getCapacity().get()) + "', expected '" + std::to_string(validCapacity.get()) + "'.");
    }
}

void RoomTest::_testFailureScenario()
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
        object->setCapacity(invalidCapacity);
        _state.set(false);
    }
    catch (std::invalid_argument &exception)
    {
        if (object->getCapacity() == invalidCapacity)
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + std::to_string(object->getCapacity().get()) + "', expected nothing.");
        }
    }
}

#endif
