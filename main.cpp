#include "domains.h"

#include <iostream>

int main(void)
{
    std::string playType;

    std::cin >> playType;
    std::cout << PlayType(playType).get() << std::endl;

    return 0;
}
