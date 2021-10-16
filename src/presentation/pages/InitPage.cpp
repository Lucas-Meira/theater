#include "../Pages.h"

Page *InitPage::show(PageHandler *handler)
{
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
        unsigned int option = handler->renderMenu(options);

        switch (option)
        {
        case 0:
            return nullptr;
        case 1:
            return new LogInPage;
        case 2:
            return new RegisterUserPage;
        case 3:
            return new ItemsMenuPage("List");
        default:
            handler->clearScreen();
            handler->print("Invalid Option " + std::to_string(option));
            handler->print("");
            break;
        }
    }

    return nullptr;
}
