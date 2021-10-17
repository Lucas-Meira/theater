#include "../../Pages.h"
#include <iomanip>

Page *ViewItemsPage::show(PageHandler *handler)
{
    handler->print("View " + _entityToView + " Page");
    handler->print("");

    if (_entityToView == "Play")
    {
        return _viewPlays(handler);
    }
    else if (_entityToView == "Room")
    {
        return _viewRooms(handler);
    }
    else if (_entityToView == "Session")
    {
        return _viewSessions(handler);
    }

    handler->clearScreen();
    handler->print("Error! Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}

Page *ViewItemsPage::_viewPlays(PageHandler *handler)
{
    SQLResult result = handler->getServices()->getPlayHandler()->list();

    if (result.status != SQLResult::SUCCESS)
    {
        handler->print("Could not get Plays.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new AuthenticatedInitPage(_user);
        }

        return new ViewItemsPage(_user, _entityToView);
    }

    auto plays = result.rows;

    if (plays.empty())
    {
        handler->print("No entries found in the database. Press any key to continue...");

        getch();

        return new AuthenticatedInitPage(_user);
    }

    std::stringstream headers;

    headers << std::setw(3) << "#" << std::setw(8) << "   ID   " << std::setw(30) << "             Name             " << std::setw(8) << "Rating" << std::setw(8) << "  Type  ";

    handler->print(headers.str());
    handler->print("");

    for (std::size_t i = 0; i < plays.size(); i++)
    {
        std::stringstream entries;

        entries << std::setw(3) << i + 1 << std::setw(8) << plays[i]["id_plays"] << std::setw(30) << plays[i]["name"] << std::setw(8) << plays[i]["rating"] << std::setw(8) << plays[i]["type"];

        handler->print(entries.str());
    }

    handler->print("");
    handler->print("Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}

Page *ViewItemsPage::_viewRooms(PageHandler *handler)
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
            return new AuthenticatedInitPage(_user);
        }

        return new ViewItemsPage(_user, _entityToView);
    }

    auto rooms = result.rows;

    if (rooms.empty())
    {
        handler->print("No entries found in the database. Press any key to continue...");

        getch();

        return new AuthenticatedInitPage(_user);
    }

    std::stringstream headers;

    headers << std::setw(3) << "#" << std::setw(6) << "  ID  " << std::setw(30) << "             Name             " << std::setw(11) << "Capacity";

    handler->print(headers.str());
    handler->print("");

    for (std::size_t i = 0; i < rooms.size(); i++)
    {
        std::stringstream entries;

        entries << std::setw(3) << i + 1 << std::setw(6) << rooms[i]["id_rooms"] << std::setw(30) << rooms[i]["name"] << std::setw(11) << rooms[i]["capacities"];

        handler->print(entries.str());
    }

    handler->print("");
    handler->print("Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}

Page *ViewItemsPage::_viewSessions(PageHandler *handler)
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
            return new AuthenticatedInitPage(_user);
        }

        return new ViewItemsPage(_user, _entityToView);
    }

    auto sessions = result.rows;

    if (sessions.empty())
    {
        handler->print("No entries found in the database. Press any key to continue...");

        getch();

        return new AuthenticatedInitPage(_user);
    }

    std::stringstream headers;
    headers << std::setw(3) << "#" << std::setw(10) << "ID" << std::setw(14) << "Date" << std::setw(9) << "Time"
            << std::setw(10) << "Play ID" << std::setw(10) << "Room ID";

    handler->print(headers.str());
    handler->print("");

    for (std::size_t i = 0; i < sessions.size(); i++)
    {
        std::stringstream entries;

        entries << std::setw(3) << i + 1 << std::setw(10) << sessions[i]["id_sessions"] << std::setw(14) << sessions[i]["date"] << std::setw(9) << sessions[i]["time"]
                << std::setw(10) << sessions[i]["id_plays_id"] << std::setw(10) << sessions[i]["id_rooms_id"];

        handler->print(entries.str());
    }

    handler->print("");
    handler->print("Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}