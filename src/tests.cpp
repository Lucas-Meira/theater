#include <iostream>

#include "domains/tests.h"
#include "domains/state.h"

int main(void)
{
    CapacityTest::UnitTest capacityTest;
    DateTest::UnitTest dateTest;
    IdCodeTest::UnitTest codeTest;

    State state = capacityTest.run();
    dateTest.run();
    codeTest.run();

    return state.get();
}