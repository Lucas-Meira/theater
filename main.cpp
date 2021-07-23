#include "domains.h"

#include <iostream>

int main(void)
{
    std::cout << Role("Actor").get() << std::endl;
    std::cout << Capacity(100).get() << std::endl;
    std::cout << Email("lima07.lucas@gmail.com").get() << std::endl;
    std::cout << Time("10:30").get() << std::endl;

    return 0;
}
