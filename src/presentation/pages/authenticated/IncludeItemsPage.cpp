#include "../../Pages.h"

Page *IncludeItemsPage::show(PageHandler *handler)
{
    handler->print("Include " + _entityToInclude + " Page");

    if (_entityToInclude == "Play")
    {
        return _includePlay(handler);
    }
    else if (_entityToInclude == "Room")
    {
        return _includeRoom(handler);
    }
    else if (_entityToInclude == "Session")
    {
        return _includeSession(handler);
    }

    handler->clearScreen();
    handler->print("Error!");

    getch();

    return new InitPage;
}

Page *IncludeItemsPage::_includePlay(PageHandler *handler)
{
    return new InitPage;
}

Page *IncludeItemsPage::_includeRoom(PageHandler *handler)
{
    return new InitPage;
}

Page *IncludeItemsPage::_includeSession(PageHandler *handler)
{
    IdCode sessionId;
    Date date;
    Time time;
    IdCode playId;
    IdCode roomId;

    std::string input;

    while (true)
    {
        handler->print("Enter Session Id: ");
        input = handler->readInput();

        try
        {
            sessionId = IdCode(input);
            break;
        }
        catch (const std::invalid_argument &)
        {
            handler->print("Invalid input. Try again? [Yy/Nn] ");
            int option = getch();
            bool tryAgain = option == 'Y' || option == 'y';

            if (!tryAgain)
            {
                return new InitPage;
            }
            handler->clearScreen();
        }
    }

    while (true)
    {
        handler->print("Enter date: ");
        input = handler->readInput();

        try
        {
            date = Date(input);
            break;
        }
        catch (const std::invalid_argument &)
        {
            handler->print("Invalid input. Try again? [Yy/Nn] ");
            int option = getch();
            bool tryAgain = option == 'Y' || option == 'y';

            if (!tryAgain)
            {
                return new InitPage;
            }
            handler->clearScreen();
        }
    }

    while (true)
    {
        handler->print("Enter time: ");
        input = handler->readInput();

        try
        {
            time = Time(input);
            break;
        }
        catch (const std::invalid_argument &)
        {
            handler->print("Invalid input. Try again? [Yy/Nn] ");
            int option = getch();
            bool tryAgain = option == 'Y' || option == 'y';

            if (!tryAgain)
            {
                return new InitPage;
            }
            handler->clearScreen();
        }
    }

    while (true)
    {
        handler->print("Enter play id: ");
        input = handler->readInput();

        try
        {
            playId = IdCode(input);

            SQLResult result = handler->getServices()->getPlayHandler()->search(playId);

            std::vector<std::map<std::string, std::string>> plays = result.rows;

            if (plays.empty())
            {
                handler->print("No play with Id Code " + playId.get() + " exists. Try again? [Yy/Nn] ");
                int option = getch();
                bool tryAgain = option == 'Y' || option == 'y';

                if (!tryAgain)
                {
                    return new InitPage;
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
                return new InitPage;
            }
            handler->clearScreen();
        }
    }

    while (true)
    {
        handler->print("Enter room id: ");
        input = handler->readInput();

        try
        {
            roomId = IdCode(input);

            SQLResult result = handler->getServices()->getRoomHandler()->search(roomId);

            std::vector<std::map<std::string, std::string>> rooms = result.rows;

            if (rooms.empty())
            {
                handler->print("No room with Id Code " + roomId.get() + " exists. Try again? [Yy/Nn] ");
                int option = getch();
                bool tryAgain = option == 'Y' || option == 'y';

                if (!tryAgain)
                {
                    return new InitPage;
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
                return new InitPage;
            }
            handler->clearScreen();
        }
    }

    SQLResult result = handler->getServices()->getSessionHandler()->create(Session(sessionId, date, time), playId, roomId);

    if (result.status != SQLResult::SUCCESS)
    {
        handler->print("Could not create a Session.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new InitPage;
        }

        return new IncludeItemsPage(_entityToInclude);
    }

    handler->print("Successfully created a Session! Press any key to continue...");

    getch();

    return new InitPage;
}