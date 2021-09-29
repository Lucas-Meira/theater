#include "../../Pages.h"

Page *AuthenticatedInitPage::show(PageHandler *handler)
{
    unsigned int option;

    handler->print("Hello, " + _firstName.get() + " " + _lastName.get() + "!");
    handler->print("");

    const std::vector<std::string> options{
        "List Items",
        "Include Items",
        "Delete Items",
        "Edit Items",
        "View Items",
        "Modify Profile",
        "Delete Profile",
        "Enroll in a Play",
        "Disenroll from a Play",
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
            return new RegisterUserPage;
        case 6:
            return new UpdateUserPage(_registration);
        case 7:
            return new DeleteUserPage(_registration);

        default:
            handler->clearScreen();
            handler->print("Invalid Option " + std::to_string(option));
            handler->print("");
            break;
        }
    }

    return nullptr;
}