#include "tests.h"

#include <iostream>
namespace DateTest
{
    void UnitTest::_setUp()
    {
        date = new Date();
        _state.set(true);
    }

    void UnitTest::_tearDown()
    {
        delete date;
    }

    bool UnitTest::_testSuccessScenario()
    {
        for (const std::string &validValue : VALID_VALUES)
        {
            try
            {
                date->set(validValue);

                if (date->get() != validValue)
                {
                    std::cout << "Expected: " << validValue << std::endl
                              << "Got: " << date->get() << std::endl;

                    _state.set(false);

                    return false;
                }
            }
            catch (std::invalid_argument &exception)
            {
                std::cout << exception.what() << std::endl;

                _state.set(false);

                return false;
            }
        }

        return true;
    }

    bool UnitTest::_testFailureScenario()
    {
        for (const std::string &invalidValue : INVALID_VALUES)
        {
            try
            {
                date->set(invalidValue);

                std::cout << "Valid value " << invalidValue << std::endl;

                _state.set(false);

                return false;
            }
            catch (std::invalid_argument &exception)
            {
                continue;
            }
        }

        return true;
    }

    void UnitTest::_printTestStatusMessage(std::string testName, bool passed)
    {
        if (passed)
        {
            std::cout << "\u001b[32m[  PASSED  ]\u001b[0m " << testName << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << "\u001b[31m[  FAILED  ]\u001b[0m " << testName << std::endl
                      << std::endl;
        }
    }

    State UnitTest::run()
    {
        std::cout << "[==========] Running Date tests.\n";

        std::cout << "[==========] Running SetUp()\n\n";

        _setUp();

        std::cout << "[ RUN      ] Success Scenario\n\n";

        bool passed = _testSuccessScenario();

        _printTestStatusMessage("Success Scenario", passed);

        std::cout << "[ RUN      ] Failure Scenario\n\n";

        passed = _testFailureScenario();

        _printTestStatusMessage("Failure Scenario", passed);

        std::cout << "[==========] Running TearDown()\n";
        _tearDown();

        std::cout << "\n[==========] Finished 2 tests.\n\n";

        return _state;
    }
}
