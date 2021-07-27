#include <iostream>

#include "domains/tests.h"
#include "domains/state.h"

int main(void)
{
    CapacityTest::UnitTest capacityTest;
    DateTest::UnitTest dateTest;
    EmailTest::UnitTest emailTest;
    IdCodeTest::UnitTest idTest;
    ImmatriculationTest::UnitTest immatriculationTest;
    NameTest::UnitTest nameTest;
    PasswordTest::UnitTest passwordTest;
    PhoneNumberTest::UnitTest phoneNumberTest;
    PlayTypeTest::UnitTest playTypeTest;
    RatingTest::UnitTest ratingTest;
    RoleTest::UnitTest roleTest;
    TimeTest::UnitTest timeTest;

    State state = capacityTest.run();
    dateTest.run();
    emailTest.run();
    idTest.run();
    immatriculationTest.run();
    nameTest.run();
    passwordTest.run();
    phoneNumberTest.run();
    playTypeTest.run();
    ratingTest.run();
    roleTest.run();
    timeTest.run();

    return state.get();
}