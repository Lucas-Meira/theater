#include "../../Pages.h"

Page *DeleteItemsPage::show(PageHandler *handler)
{
    handler->print("Include " + _entityToDelete + " Page");

    if (_entityToDelete == "Play")
    {
        return _deletePlay(handler);
    }
    else if (_entityToDelete == "Room")
    {
        return _deleteRoom(handler);
    }
    else if (_entityToDelete == "Session")
    {
        return _deleteSession(handler);
    }

    handler->clearScreen();
    handler->print("Error! Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}

Page *DeleteItemsPage::_deletePlay(PageHandler *handler)
{
    handler->print("Page not yet implemented. Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}

Page *DeleteItemsPage::_deleteRoom(PageHandler *handler)
{
    handler->print("Page not yet implemented. Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}

Page *DeleteItemsPage::_deleteSession(PageHandler *handler)
{
    IdCode sessionId;

    while (true)
    {
        handler->print("Enter the Id of the Session to delete: ");
        std::string input = handler->readInput();

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
                return new AuthenticatedInitPage(_user);
            }
            handler->clearLines(2);
        }
    }

    SQLResult result = handler->getServices()->getSessionHandler()->remove(sessionId);

    if (result.status != SQLResult::SUCCESS)
    {
        handler->print("Could not delete Session.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new AuthenticatedInitPage(_user);
        }

        return new DeleteItemsPage(_user, _entityToDelete);
    }

    handler->print("Successfully deleted Session! Press any key to continue...");

    getch();

    return new AuthenticatedInitPage(_user);
}