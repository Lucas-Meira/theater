#include "domains.h"

#include <iostream>

int main(void)
{
    std::string number;

    std::cin >> number;
    std::cout << PhoneNumber(number).get() << std::endl;

    return 0;
}
