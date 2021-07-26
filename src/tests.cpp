#include <iostream>

#include "domains/tests.h"
#include "domains/state.h"

int main(void)
{
    ImmatriculationTest::UnitTest test;
    State state = test.run();

    return state.get();
}