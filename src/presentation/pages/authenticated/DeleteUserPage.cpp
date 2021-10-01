#include "../../Pages.h"

Page *DeleteUserPage::show(PageHandler *handler)
{
    SQLResult result = handler->getServices()->getParticipantHandler()->search(_user.getRegistration());

    if (result.rows.size() == 0)
    {
        handler->print("Something went wrong! Press any key to continue...");

        getch();

        return new InitPage;
    }

    auto user = result.rows[0];

    handler->print("Registration: " + user["registration"]);
    handler->print("First Name: " + user["first_name"]);
    handler->print("Last Name: " + user["last_name"]);
    handler->print("Email: " + user["email"]);
    handler->print("Phone Number: " + user["phone_number"]);
    handler->print("Role: " + user["role"]);
    handler->print("Play ID: " + user["id_plays_id"]);
    handler->print("");
    handler->print("Are you sure you want to delete this user? [Yy/Nn]");

    int option = getch();
    bool deleteUser = option == 'Y' || option == 'y';

    if (!deleteUser)
    {
        return new AuthenticatedInitPage(_user);
    }

    result = handler->getServices()->getParticipantHandler()->remove(_user.getRegistration());

    if (result.status != SQLResult::SUCCESS)
    {
        handler->print("Could not remove user.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new DeleteUserPage(_user);
        }

        return new AuthenticatedInitPage(_user);
    }

    handler->print("Successfully deleted user! Press any key to continue...");

    getch();

    return new InitPage;
}