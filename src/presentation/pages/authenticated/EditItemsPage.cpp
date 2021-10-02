#include "../../Pages.h"

Page *EditItemsPage::show(PageHandler *handler)
{
    handler->print("Edit " + _entityToEdit + " Page");

    if (_entityToEdit == "Play")
    {
        return _editPlay(handler);
    }
    else if (_entityToEdit == "Room")
    {
        return _editRoom(handler);
    }
    else if (_entityToEdit == "Session")
    {
        return _editSession(handler);
    }

    handler->clearScreen();
    handler->print("Error! Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}

Page *EditItemsPage::_editPlay(PageHandler *handler)
{
    handler->print("Page not yet implemented. Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}

Page *EditItemsPage::_editRoom(PageHandler *handler)
{
    handler->print("Page not yet implemented. Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}

Page *EditItemsPage::_editSession(PageHandler *handler)
{
    Session newSession;
    IdCode newPlayId;
    IdCode newRoomId;

    while (true)
    {
        handler->print("Enter the Id of the Session to edit: ");
        std::string input = handler->readInput();

        try
        {
            newSession.setId(input);
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

    SQLResult result = handler->getServices()->getSessionHandler()->search(newSession.getId());

    if (result.rows.size() == 0)
    {
        handler->print("Something went wrong!");

        return new InitPage;
    }

    auto sessionInDb = result.rows[0];

    while (true)
    {
        handler->print("Edit Date? " + sessionInDb["date"] + " [Yy/Nn]");

        int option = getch();
        bool edit = option == 'Y' || option == 'y';

        if (!edit)
        {
            newSession.setDate(sessionInDb["date"]);
            break;
        }

        handler->print("Enter new Date: ");
        std::string input = handler->readInput();

        try
        {
            newSession.setDate(input);
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

    while (true)
    {
        handler->print("Edit Time? " + sessionInDb["time"] + " [Yy/Nn]");

        int option = getch();
        bool edit = option == 'Y' || option == 'y';

        if (!edit)
        {
            newSession.setTime(sessionInDb["time"]);
            break;
        }

        handler->print("Enter new Time: ");
        std::string input = handler->readInput();

        try
        {
            newSession.setTime(input);
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

    while (true)
    {
        handler->print("Edit Play? " + sessionInDb["id_plays_id"] + " [Yy/Nn]");

        int option = getch();
        bool edit = option == 'Y' || option == 'y';

        if (!edit)
        {
            newPlayId = IdCode(sessionInDb["id_plays_id"]);
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

    while (true)
    {
        handler->print("Edit Room? " + sessionInDb["id_rooms_id"] + " [Yy/Nn]");

        int option = getch();
        bool edit = option == 'Y' || option == 'y';

        if (!edit)
        {
            newRoomId = IdCode(sessionInDb["id_rooms_id"]);
            break;
        }

        handler->print("Enter new Room Id: ");
        std::string input = handler->readInput();

        try
        {
            newRoomId = IdCode(input);

            SQLResult result = handler->getServices()->getRoomHandler()->search(newRoomId);

            std::vector<std::map<std::string, std::string>> rooms = result.rows;

            if (rooms.empty())
            {
                handler->print("No room with Id Code " + newRoomId.get() + " exists. Try again? [Yy/Nn] ");
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
    handler->print("Date: " + newSession.getDate().get());
    handler->print("Time: " + newSession.getTime().get());
    handler->print("Play Id: " + newPlayId.get());
    handler->print("Room Id: " + newRoomId.get());
    handler->print("Is the info provided correct? [Yy/Nn]");

    int option = getch();
    bool isCorrect = option == 'Y' || option == 'y';

    if (!isCorrect)
    {
        return new EditItemsPage(_user, _entityToEdit);
    }

    result = handler->getServices()->getSessionHandler()->update(newSession, newPlayId, newRoomId);

    if (result.status != SQLResult::SUCCESS)
    {
        handler->print("Could not edit Session.");
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

    handler->print("Successfully edited Session! Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}