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
    else
    {
        handler->clearScreen();
        handler->print("Error!");

        getch();

        return new InitPage;
    }

    return nullptr;
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
    return new InitPage;
}