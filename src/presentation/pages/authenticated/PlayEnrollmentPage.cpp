#include "../../Pages.h"

Page *PlayEnrollmentPage::show(PageHandler *handler)
{

    handler->print("Play Enrollment Page");
    SQLResult result = handler->getServices()->getParticipantHandler()->search(_user.getRegistration());

    if (result.rows.size() == 0)
    {
        handler->print("Something went wrong!");

        getch();

        return new InitPage;
    }

    auto user = result.rows[0];
    Registration registration = Registration(user["registration"]);
    Play play;

    while (true)
    {
        handler->print("Alter Play? " + user["id_plays_id"] + " [Yy/Nn]");

        int option = getch();
        bool alter = option == 'Y' || option == 'y';

        if (!alter)
        {
            play.setId(user["id_plays_id"]);
            break;
        }

        handler->print("Enter new Play Id: ");

        std::string input = handler->readInput();

        try
        {
            play.setId(input);
            break;
        }
        catch (const std::invalid_argument &)
        {
            handler->print("Invalid input. Try again? [Yy/Nn] ");
            int option = getch();
            bool tryAgain = option == 'Y' || option == 'y';

            if (!tryAgain)
            {
                return new AuthenticatedInitPage(_user);
            }
            handler->clearLines(3);
        }

    }
    handler->clearScreen();

    result = handler->getServices()->getPlayHandler()->search(play.getId());

    if (result.rows.empty())
    {
        handler->print("No play with id " + play.getId().get() + " found in the database!");
        handler->print("");
        handler->print("Press any key to continue...");

        getch();

        return new AuthenticatedInitPage(_user);
    }

    auto playInDb = result.rows[0];

    handler->clearScreen();

    handler->print("Please check the info provided");
    handler->print("");
    handler->print("Play Id: " + playInDb["id_plays"]);
    handler->print("Name: " + playInDb["name"]);
    handler->print("Type: " + playInDb["type"]);
    handler->print("Rating: " + playInDb["rating"]);

    handler->print("Is the info provided correct? [Yy/Nn]");

    int option = getch();
    bool isCorrect = option == 'Y' || option == 'y';

    if (!isCorrect)
    {
        return new PlayEnrollmentPage(_user);
    }

    result = handler->getServices()->getParticipantHandler()->updatePlay(registration, play.getId());

    if (result.status != SQLResult::SUCCESS)
    {
        handler->print("Unable to enroll in Play.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new AuthenticatedInitPage(_user);
        }

        return new PlayEnrollmentPage(_user);
    }

    handler->print("Successfully enrolled in Play! Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}
