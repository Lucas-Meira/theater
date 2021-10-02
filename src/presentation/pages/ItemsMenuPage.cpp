#include "../Pages.h"

Page *ItemsMenuPage::show(PageHandler *handler)
{
    handler->print(_action + " items options");
    handler->print("");

    const std::vector<std::string> options{
        "Play",
        "Room",
        "Session",
        "Return"};

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
        handler->print("Error! Press any key to continue...");

        getch();

        return new AuthenticatedInitPage(_user);
    }
}

Page *ItemsMenuPage::_handleList(PageHandler *handler, unsigned int option)
{
    switch (option)
    {
    case 0:
        return new AuthenticatedInitPage(_user);
    case 1:
        return _isLoggedIn ? new ListItemsPage(_user, "Play") : new ListItemsPage("Play");
    case 2:
        return _isLoggedIn ? new ListItemsPage(_user, "Room") : new ListItemsPage("Room");
    case 3:
        return _isLoggedIn ? new ListItemsPage(_user, "Session") : new ListItemsPage("Session");
    default:
        handler->clearScreen();
        handler->print("Invalid Option " + std::to_string(option));
        handler->print("Press enter to continue");
        getch();
        return _isLoggedIn ? new ItemsMenuPage(_user, _action) : new ItemsMenuPage(_action);
    }
}

Page *ItemsMenuPage::_handleInclude(PageHandler *handler, unsigned int option)
{
    switch (option)
    {
    case 0:
        return new AuthenticatedInitPage(_user);
    case 1:
        return new IncludeItemsPage(_user, "Play");
    case 2:
        return new IncludeItemsPage(_user, "Room");
    case 3:
        return new IncludeItemsPage(_user, "Session");
    default:
        handler->clearScreen();
        handler->print("Invalid Option " + std::to_string(option));
        handler->print("Press enter to continue");
        getch();
        return new ItemsMenuPage(_user, _action);
    }
}

Page *ItemsMenuPage::_handleDelete(PageHandler *handler, unsigned int option)
{
    switch (option)
    {
    case 0:
        return new AuthenticatedInitPage(_user);
    case 1:
        return new DeleteItemsPage(_user, "Play");
    case 2:
        return new DeleteItemsPage(_user, "Room");
    case 3:
        return new DeleteItemsPage(_user, "Session");
    default:
        handler->clearScreen();
        handler->print("Invalid Option " + std::to_string(option));
        handler->print("Press enter to continue");
        getch();
        return new ItemsMenuPage(_user, _action);
    }
}

Page *ItemsMenuPage::_handleEdit(PageHandler *handler, unsigned int option)
{
    switch (option)
    {
    case 0:
        return new AuthenticatedInitPage(_user);
    case 1:
        return new EditItemsPage(_user, "Play");
    case 2:
        return new EditItemsPage(_user, "Room");
    case 3:
        return new EditItemsPage(_user, "Session");
    default:
        handler->clearScreen();
        handler->print("Invalid Option " + std::to_string(option));
        handler->print("Press enter to continue");
        getch();
        return new ItemsMenuPage(_user, _action);
    }
}

Page *ItemsMenuPage::_handleView(PageHandler *handler, unsigned int option)
{
    switch (option)
    {
    case 0:
        return new AuthenticatedInitPage(_user);
    case 1:
        return new ViewItemsPage(_user, "Play");
    case 2:
        return new ViewItemsPage(_user, "Room");
    case 3:
        return new ViewItemsPage(_user, "Session");
    default:
        handler->clearScreen();
        handler->print("Invalid Option " + std::to_string(option));
        handler->print("Press enter to continue");
        getch();
        return new ItemsMenuPage(_user, _action);
    }
}