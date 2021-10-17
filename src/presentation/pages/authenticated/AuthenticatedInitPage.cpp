#include "../../Pages.h"

Page *AuthenticatedInitPage::show(PageHandler *handler)
{
    unsigned int option;

    handler->print("Hello, " + _user.getFirstName().get() + " " + _user.getLastName().get() + "!");
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
        case 1:
            return new ItemsMenuPage(_user, "List");
        case 2:
            return new ItemsMenuPage(_user, "Include");
        case 3:
            return new ItemsMenuPage(_user, "Delete");
        case 4:
            return new ItemsMenuPage(_user, "Edit");
        case 5:
            return new ItemsMenuPage(_user, "View");
        case 6:
            return new UpdateUserPage(_user);
        case 7:
            return new DeleteUserPage(_user);
        case 8:
            return new PlayEnrollmentPage(_user);

        default:
            handler->clearScreen();
            handler->print("Invalid Option " + std::to_string(option));
            handler->print("");
            break;
        }
    }

    return nullptr;
}
