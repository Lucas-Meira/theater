#include <iostream>

#include "domains/tests.h"
#include "state.h"

int8_t runTests();
int8_t checkResults(std::vector<State> &testResults);

int main(void)
{
    return runTests();
}

int8_t runTests()
{
    CapacityTest::UnitTest capacityTest;
    DateTest::UnitTest dateTest;
    EmailTest::UnitTest emailTest;
    IdCodeTest::UnitTest idTest;
    RegistrationTest::UnitTest registrationTest;
    NameTest::UnitTest nameTest;
    PasswordTest::UnitTest passwordTest;
    PhoneNumberTest::UnitTest phoneNumberTest;
    PlayTypeTest::UnitTest playTypeTest;
    RatingTest::UnitTest ratingTest;
    RoleTest::UnitTest roleTest;
    TimeTest::UnitTest timeTest;

    std::vector<State> testResults{};

    State state = capacityTest.run();
    testResults.push_back(state);
    state = dateTest.run();
    testResults.push_back(state);
    state = emailTest.run();
    testResults.push_back(state);
    state = idTest.run();
    testResults.push_back(state);
    state = registrationTest.run();
    testResults.push_back(state);
    state = nameTest.run();
    testResults.push_back(state);
    state = passwordTest.run();
    testResults.push_back(state);
    state = phoneNumberTest.run();
    testResults.push_back(state);
    state = playTypeTest.run();
    testResults.push_back(state);
    state = ratingTest.run();
    testResults.push_back(state);
    state = roleTest.run();
    testResults.push_back(state);
    state = timeTest.run();
    testResults.push_back(state);

    return checkResults(testResults);
}

int8_t checkResults(std::vector<State> &testResults)
{
    for (State &state : testResults)
    {
        if (state.get() != state.SUCCESS)
        {
            return state.get();
        }
    }

    return State::SUCCESS;
}