#include "domains.h"

#include <iostream>

int main(void)
{
    std::string password;

    std::cin >> password;
    std::cout << Password(password).get() << std::endl;

    return 0;
}
