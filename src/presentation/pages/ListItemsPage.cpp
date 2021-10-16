#include "../Pages.h"
#include <iomanip>

Page *ListItemsPage::show(PageHandler *handler)
{
    handler->print("List " + _entityToList + " Page");
    handler->print("");

    if (_entityToList == "Play")
    {
        return _listPlays(handler);
    }
    else if (_entityToList == "Room")
    {
        return _listRooms(handler);
    }
    else if (_entityToList == "Session")
    {
        return _listSessions(handler);
    }

    handler->clearScreen();
    handler->print("Error! Press any key to continue...");

    getch();

    if (_isLoggedIn)
    {
        return new AuthenticatedInitPage(_user);
    }

    return new InitPage;
}

Page *ListItemsPage::_listPlays(PageHandler *handler)
{
    handler->print("Page not yet implemented. Press any key to continue...");

    getch();

    if (_isLoggedIn)
    {
        return new AuthenticatedInitPage(_user);
    }

    return new InitPage;
}

Page *ListItemsPage::_listRooms(PageHandler *handler)
{
    SQLResult result = handler->getServices()->getRoomHandler()->list();

    if (result.status != SQLResult::SUCCESS)
    {
        handler->print("Could not get Rooms.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            if (_isLoggedIn)
            {
                return new AuthenticatedInitPage(_user);
            }

            return new InitPage;
        }

        if (_isLoggedIn)
        {
            return new ListItemsPage(_user, _entityToList);
        }

        return new ListItemsPage(_entityToList);
    }

    auto rooms = result.rows;

    if (rooms.empty())
    {
        handler->print("No entries found in the database. Press any key to continue...");

        getch();

        if (_isLoggedIn)
        {
            return new AuthenticatedInitPage(_user);
        }

        return new InitPage;
    }

    std::stringstream headers;

    headers << std::setw(3) << " # " << std::setw(30) << "             Name             ";

    handler->print(headers.str());
    handler->print("");

    for (std::size_t i = 0; i < rooms.size(); i++)
    {
        std::stringstream entries;

        entries << std::setw(3) << i + 1 << std::setw(30) << rooms[i]["name"];

        handler->print(entries.str());
    }

    handler->print("");
    handler->print("Press any key to continue...");

    getch();

    if (_isLoggedIn)
    {
        return new AuthenticatedInitPage(_user);
    }

    return new InitPage;
}

Page *ListItemsPage::_listSessions(PageHandler *handler)
{
    SQLResult result = handler->getServices()->getSessionHandler()->list();

    if (result.status != SQLResult::SUCCESS)
    {
        handler->print("Could not get Sessions.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            if (_isLoggedIn)
            {
                return new AuthenticatedInitPage(_user);
            }

            return new InitPage;
        }

        if (_isLoggedIn)
        {
            return new ListItemsPage(_user, _entityToList);
        }

        return new ListItemsPage(_entityToList);
    }

    auto sessions = result.rows;

    if (sessions.empty())
    {
        handler->print("No entries found in the database. Press any key to continue...");

        getch();

        if (_isLoggedIn)
        {
            return new AuthenticatedInitPage(_user);
        }

        return new InitPage;
    }

    std::stringstream headers;
    headers << std::setw(3) << "#" << std::setw(10) << "ID" << std::setw(14) << "Date" << std::setw(9) << "Time";

    handler->print(headers.str());
    handler->print("");

    for (std::size_t i = 0; i < sessions.size(); i++)
    {
        std::stringstream entries;

        entries << std::setw(3) << i + 1 << std::setw(10) << sessions[i]["id_sessions"] << std::setw(14) << sessions[i]["date"] << std::setw(9) << sessions[i]["time"];

        handler->print(entries.str());
    }

    handler->print("");
    handler->print("Press any key to continue...");

    getch();

    if (_isLoggedIn)
    {
        return new AuthenticatedInitPage(_user);
    }

    return new InitPage;
}