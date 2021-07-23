#include "domains.h"

#include <iostream>

int main(void)
{
    int testedValue;

    std::cin >> testedValue;
    std::cout << Capacity(testedValue).get() << std::endl;

    return 0;
}
