#include "../../Pages.h"

Page *PlayDisenrollmentPage::show(PageHandler *handler)
{

    handler->print("Play Disenrollment Page");
    SQLResult result = handler->getServices()->getParticipantHandler()->search(_user.getRegistration());

    if (result.rows.size() == 0)
    {
        handler->print("Something went wrong!");

        getch();

        return new InitPage;
    }

    auto user = result.rows[0];
    Registration registration = Registration(user["registration"]);

    handler->print("disenroll from Play? " + user["id_plays_id"] + " [Yy/Nn]");

    int option = getch();
    bool disenroll = option == 'Y' || option == 'y';

    if (!disenroll)
    {
        return new AuthenticatedInitPage(_user);
    }

    handler->clearScreen();

    result = handler->getServices()->getParticipantHandler()->updatePlay(registration, IdCode(""));

    if (result.status != SQLResult::SUCCESS)
    {
        handler->print("Unable to disenroll from Play.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new AuthenticatedInitPage(_user);
        }

        return new PlayDisenrollmentPage(_user);
    }

    handler->print("Successfully disenrolled from Play! Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}
