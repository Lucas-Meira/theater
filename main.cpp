#include "domains.h"

#include <iostream>

int main(void)
{
    std::string testedValue;

    std::cin >> testedValue;
    std::cout << Email(testedValue).get() << std::endl;

    return 0;
}
