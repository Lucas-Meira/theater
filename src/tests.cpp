#include <iostream>

#include "domains/tests.h"
#include "domains/state.h"

int main(void)
{
    CapacityTest::UnitTest capacityTest;

    State state = capacityTest.run();

    return state.get();
}