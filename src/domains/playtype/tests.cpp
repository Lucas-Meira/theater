#include "tests.h"

#include <iostream>
namespace PlayTypeTest
{
    void UnitTest::_setUp()
    {
        playType = new PlayType();
        _state.set(true);
    }

    void UnitTest::_tearDown()
    {
        delete playType;
    }

    void UnitTest::_testSuccessScenario()
    {
        for (const std::string &validValue : VALID_VALUES)
        {
            try
            {
                playType->set(validValue);

                if (playType->get() != validValue)
                {
                    std::cout << "Expected: " << validValue << std::endl
                              << "Got: " << playType->get() << std::endl;

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

    void UnitTest::_testFailureScenario()
    {
        for (const std::string &invalidValue : INVALID_VALUES)
        {
            try
            {
                playType->set(invalidValue);

                std::cout << "[PlayTypeTest] Valid value '" << invalidValue << "'." << std::endl;

                _state.set(false);
            }
            catch (std::invalid_argument &exception)
            {
                continue;
            }
        }
    }

    void UnitTest::_printTestStatusMessage(std::string testName)
    {
        if (_state.get() == _state.SUCCESS)
        {
            std::cout << testName << " \u001b[32m[  PASSED  ]\u001b[0m " << std::endl;
        }
        else
        {
            std::cout << testName << " \u001b[31m[  FAILED  ]\u001b[0m " << std::endl;
        }
    }

    State UnitTest::run()
    {
        std::cout << "[PlayTypeTest] RUN" << std::endl;

        _setUp();
        _testSuccessScenario();
        _testFailureScenario();
        _tearDown();

        _printTestStatusMessage("[PlayTypeTest]");

        std::cout << "[PlayTypeTest] DONE" << std::endl;

        return _state;
    }
}
