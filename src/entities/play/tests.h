#ifndef PLAY_TEST_H
#define PLAY_TEST_H

#include "play.h"
#include "../../state.h"

namespace PlayTest
{
    class UnitTest
    {
    private:
        Play *play;
        State _state;

        inline static const std::string _classUnderTest{"[PlayTest]"};

        inline static const IdCode validId{"AA0000"};
        inline static const Name validName{"The Phantom Ot Opera"};
        inline static const PlayType validType{"Musical"};
        inline static const Rating validRating{"12"};

        inline static const std::string invalidId{"ABC012"};
        inline static const std::string invalidName{"The Phantom of the Opera"};
        inline static const std::string invalidType{"Rock"};
        inline static const std::string invalidRating{"11"};

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
        play = new Play();

        _state.set(true);
    }

    void UnitTest::_tearDown()
    {
        delete play;
    }

    void UnitTest::_testSuccessScenario()
    {
        play->setId(validId);

        if (play->getId().get() != validId.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + play->getId().get() + "', expected '" + validId.get() + +"'.");
        }

        play->setName(validName);

        if (play->getName().get() != validName.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + play->getName().get() + "', expected '" + validName.get() + "'.");
        }

        play->setType(validType);

        if (play->getType().get() != validType.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + play->getType().get() + "', expected '" + validType.get() + "'.");
        }

        play->setRating(validRating);

        if (play->getRating().get() != validRating.get())
        {
            _state.set(false);
            throw std::invalid_argument("Got '" + play->getRating().get() + "', expected '" + validRating.get() + "'.");
        }
    }

    void UnitTest::_testFailureScenario()
    {
        try
        {
            play->setId(invalidId);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (play->getId().get() == invalidId)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + play->getId().get() + "', expected nothing.");
            }
        }

        try
        {
            play->setName(invalidName);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (play->getName().get() == invalidName)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + play->getName().get() + "', expected nothing.");
            }
        }

        try
        {
            play->setType(invalidType);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (play->getType().get() == invalidType)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + play->getType().get() + "', expected nothing.");
            }
        }

        try
        {
            play->setRating(invalidRating);
            _state.set(false);
        }
        catch (std::invalid_argument &exception)
        {
            if (play->getRating().get() == invalidRating)
            {
                _state.set(false);
                throw std::invalid_argument("Got '" + play->getRating().get() + "', expected nothing.'");
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