#include <iostream>

#include "domains/tests.h"
#include "domains/state.h"

int main(void)
{
    CapacityTest::UnitTest capacityTest;
    DateTest::UnitTest dateTest;

    State state = capacityTest.run();
    State state2 = dateTest.run();

    return state.get();
}