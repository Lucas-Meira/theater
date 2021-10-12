#include "../../Pages.h"
//TENHO QUE ARRUMAR AINDA!!!!!!!!!!!!!!!

Page *registrationPlayInUse::show(PageHandler *handler)
{
    handler->print("unregister  Play in User Page");
    handler->print("Play's:");
    std::stringstream query;

    query << "SELECT * FROM Plays;";

    return DBHandler::getInstance()->execute(query);
    Participant participant;
    IdCode newPlayId;

    while (true)
    {
        handler->print("Enter the Id of the participant to edit: ");
        std::string input = handler->readInput();

        try
        {
            participant.setId(input);
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
            handler->clearLines(2);
        }
    }

    SQLResult result = handler->getServices()->getParticipantHandler()->search(participant.getId());

    if (result.rows.size() == 0)
    {
        handler->print("Something went wrong!");

        return new InitPage;
    }

    auto participantInDb = result.rows[0];

    while (true)
    {
        handler->print("Edit Play? " + participantInDb["id_plays_id"] + " [Yy/Nn]");

        int option = getch();
        bool edit = option == 'Y' || option == 'y';

        if (!edit)
        {
            newPlayId = IdCode(participantInDb["id_plays_id"]);
            break;
        }

        handler->print("Enter new Play Id: ");
        std::string input = handler->readInput();

        try
        {
            newPlayId = IdCode(input);

            SQLResult result = handler->getServices()->getPlayHandler()->search(newPlayId);

            std::vector<std::map<std::string, std::string>> plays = result.rows;

            if (plays.empty())
            {
                handler->print("No play with Id Code " + newPlayId.get() + " exists. Try again? [Yy/Nn] ");
                int option = getch();
                bool tryAgain = option == 'Y' || option == 'y';

                if (!tryAgain)
                {
                    return new AuthenticatedInitPage(_user);
                }
            }
            else
            {
                break;
            }
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

    handler->print("Please check the info provided");
    handler->print("");
    handler->print("First Name: " + participant.getFirstName().get());
    handler->print("Last Name: " + participant.getLastName().get());
    handler->print("Email: " + participant.getEmail().get());
    handler->print("Phone Number: " + participant.getPhoneNumber().get());
    handler->print("Password: " + participant.getPassword().get());
    handler->print("Role: " + participant.getRole().get());
    handler->print("Play Id: " + newPlayId.get());

    handler->print("Is the info provided correct? [Yy/Nn]");

    int option = getch();
    bool isCorrect = option == 'Y' || option == 'y';

    if (!isCorrect)
    {
        return new EditItemsPage(_user, _entityToEdit);
    }

    result = handler->getServices()->getParticipantHandler()->update_play(participant, newPlayId);

    if (result.status != SQLResult::SUCCESS)
    {
        handler->print("Unable to insert user.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new AuthenticatedInitPage(_user);
        }

        return new EditItemsPage(_user, _entityToEdit);
    }

    handler->print("Successfully insert Play in User! Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}