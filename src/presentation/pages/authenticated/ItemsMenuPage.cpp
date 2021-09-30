#include "../../Pages.h"

Page *ItemsMenuPage::show(PageHandler *handler)
{
    handler->print(_action + " items options");
    handler->print("");

    const std::vector<std::string> options{
        "Play",
        "Room",
        "Session",
        "Quit"};

    handler->print("");
    unsigned int option = handler->renderMenu(options);

    if (_action == "List")
    {
        return _handleList(handler, option);
    }

    else if (_action == "Include")
    {
        return _handleInclude(handler, option);
    }

    else if (_action == "Delete")
    {
        return _handleDelete(handler, option);
    }

    else if (_action == "Edit")
    {
        return _handleEdit(handler, option);
    }
    else if (_action == "View")
    {
        return _handleView(handler, option);
    }
    else
    {
        handler->clearScreen();
        handler->print("Error!");

        getch();

        return new InitPage;
    }
}

Page *ItemsMenuPage::_handleList(PageHandler *handler, unsigned int option)
{
    switch (option)
    {
    case 0:
        return nullptr;
    case 1:
    case 2:
    case 3:
        return new InitPage;
    default:
        handler->clearScreen();
        handler->print("Invalid Option " + std::to_string(option));
        handler->print("");
        break;
    }
}

Page *ItemsMenuPage::_handleInclude(PageHandler *handler, unsigned int option)
{
    switch (option)
    {
    case 0:
        return nullptr;
    case 1:
        return new IncludeItemsPage("Play");
    case 2:
        return new IncludeItemsPage("Room");
    case 3:
        return new IncludeItemsPage("Session");
    default:
        handler->clearScreen();
        handler->print("Invalid Option " + std::to_string(option));
        handler->print("Press enter to continue");
        getch();
        return new ItemsMenuPage(_action);
    }
}

Page *ItemsMenuPage::_handleDelete(PageHandler *handler, unsigned int option)
{
    switch (option)
    {
    case 0:
        return nullptr;
    case 1:
        return new DeleteItemsPage("Play");
    case 2:
        return new DeleteItemsPage("Room");
    case 3:
        return new DeleteItemsPage("Session");
    default:
        handler->clearScreen();
        handler->print("Invalid Option " + std::to_string(option));
        handler->print("Press enter to continue");
        getch();
        return new ItemsMenuPage(_action);
    }
}

Page *ItemsMenuPage::_handleEdit(PageHandler *handler, unsigned int option)
{
    switch (option)
    {
    case 0:
        return nullptr;
    case 1:
    case 2:
    case 3:
        return new InitPage;
    default:
        handler->clearScreen();
        handler->print("Invalid Option " + std::to_string(option));
        handler->print("Press enter to continue");
        getch();
        return new ItemsMenuPage(_action);
    }
}

Page *ItemsMenuPage::_handleView(PageHandler *handler, unsigned int option)
{
    switch (option)
    {
    case 0:
        return nullptr;
    case 1:
    case 2:
    case 3:
        return new InitPage;
    default:
        handler->clearScreen();
        handler->print("Invalid Option " + std::to_string(option));
        handler->print("Press enter to continue");
        getch();
        return new ItemsMenuPage(_action);
    }
}