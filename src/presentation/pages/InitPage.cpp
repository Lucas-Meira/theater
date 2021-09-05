#include "../Pages.h"

Page *InitPage::show(PageHandler *handler)
{
    unsigned int option;

    handler->print("Welcome to UnB Theater!");
    handler->print("");

    const std::vector<std::string> options{
        "Sign In",
        "Register",
        "List Items",
        "Quit"};

    while (true)
    {
        handler->print("");
        option = handler->renderMenu(options);

        switch (option)
        {
        case 0:
            return nullptr;
        case 2:
            return new RegisterPage;

        default:
            handler->clearScreen();
            handler->print("Invalid Option " + std::to_string(option));
            handler->print("");
            break;
        }
    }

    return nullptr;
}