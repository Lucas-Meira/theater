#include <iostream>

#include "domains/tests.h"
#include "entities/tests.h"
#include "state.h"

int8_t runTests();
int8_t runDomainTests();
int8_t runEntitiesTests();
int8_t checkResults(std::vector<State> &testResults);

int main(void)
{
    return runTests();
}

int8_t runTests()
{
    return !((runDomainTests() == State::SUCCESS) && (runEntitiesTests() == State::SUCCESS));
}

int8_t runEntitiesTests()
{
    std::cout << "Running Entities Tests\n\n";

    ParticipantTest::UnitTest participantTest;
    PlayTest::UnitTest playTest;
    RoomTest::UnitTest roomTest;
    SessionTest::UnitTest sessionTest;

    std::vector<State> testResults{};

    State state = participantTest.run();
    testResults.push_back(state);
    state = playTest.run();
    testResults.push_back(state);
    state = roomTest.run();
    testResults.push_back(state);
    state = sessionTest.run();
    testResults.push_back(state);

    std::cout << "\n";

    return checkResults(testResults);
}

int8_t runDomainTests()
{
    std::cout << "Running Domain Tests\n\n";
    CapacityTest capacityTest;
    DateTest dateTest;
    EmailTest emailTest;
    IdCodeTest idTest;
    RegistrationTest registrationTest;
    NameTest nameTest;
    PasswordTest passwordTest;
    PhoneNumberTest phoneNumberTest;
    PlayTypeTest playTypeTest;
    RatingTest ratingTest;
    RoleTest roleTest;
    TimeTest timeTest;

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

    std::cout << "\n";

    return checkResults(testResults);
}

int8_t checkResults(std::vector<State> &testResults)
{
    for (State &state : testResults)
    {
        if (state.get() != state.SUCCESS)
        {
            return State::FAILURE;
        }
    }

    return State::SUCCESS;
}