#ifndef ROOM_TEST_H
#define ROOM_TEST_H

#include "room.h"
#include "../../state.h"

namespace RoomTest
{
    class UnitTest
    {
    private:
        Room *room;
        State _state;

        inline static const std::string _classUnderTest{"[RoomTest]"};

        inline static const IdCode validId{"AA0000"};
        inline static const Name validName{"Villa Lobos"};
        inline static const Capacity validCapacity{100};

        inline static const std::string invalidId{"ABC012"};
        inline static const std::string invalidName{"Villa lobos"};
        inline static const uint16_t invalidCapacity{150};

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
        room = new Room();

        _state.set(true);
    }

    void UnitTest::_tearDown()
    {
        delete room;
    }

    void UnitTest::_testSuccessScenario()
    {
        room->setId(validId);

        if (room->getId().get() != validId.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + room->getId().get() + "', expected '" + validId.get() + +"'.");
        }

        room->setName(validName);

        if (room->getName().get() != validName.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + room->getName().get() + "', expected '" + validName.get() + "'.");
        }

        room->setCapacity(validCapacity);

        if (room->getCapacity().get() != validCapacity.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + std::to_string(room->getCapacity().get()) + "', expected '" + std::to_string(validCapacity.get()) + "'.");
        }
    }

    void UnitTest::_testFailureScenario()
    {
        try
        {
            room->setId(invalidId);
            _state.set(false);
        }
        catch (...)
        {
            if (room->getId().get() == invalidId)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + room->getId().get() + "', expected nothing.");
            }
        }

        try
        {
            room->setName(invalidName);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (room->getName().get() == invalidName)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + room->getName().get() + "', expected nothing.");
            }
        }

        try
        {
            room->setCapacity(invalidCapacity);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (room->getCapacity().get() == invalidCapacity)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + std::to_string(room->getCapacity().get()) + "', expected nothing.");
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