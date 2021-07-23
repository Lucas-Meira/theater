#include "domains.h"

#include <iostream>

int main(void)
{
    std::string name;

    std::getline(std::cin, name);

    std::cout << Name(name).get() << std::endl;

    return 0;
}
