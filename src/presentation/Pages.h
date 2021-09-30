#ifndef PAGES_H
#define PAGES_H

#include "PageHandler.h"

class Page
{
public:
    virtual Page *show(PageHandler *handler) = 0;

    virtual ~Page(){};
};

class InitPage : public Page
{
public:
    Page *show(PageHandler *handler);

    ~InitPage(){};
};

class RegisterUserPage : public Page
{
public:
    Page *show(PageHandler *handler);

    ~RegisterUserPage(){};
};

class RegisterItemPage : public Page
{
public:
    Page *show(PageHandler *handler);

    ~RegisterItemPage(){};
};

class ListItemsPage : public Page
{
public:
    Page *show(PageHandler *handler);

    ~ListItemsPage(){};
};

class LogInPage : public Page
{
public:
    Page *show(PageHandler *handler);

    ~LogInPage(){};
};

class AuthenticatedInitPage : public Page
{
private:
    Name _firstName;
    Name _lastName;
    Registration _registration;

public:
    AuthenticatedInitPage(const Name &firstName, const Name &lastName, const Registration &registration) : _firstName(firstName), _lastName(lastName), _registration(registration)
    {
    }

    Page *show(PageHandler *handler);

    ~AuthenticatedInitPage(){};
};

class UpdateUserPage : public Page
{
private:
    Registration _registration;

public:
    UpdateUserPage(const Registration &registration) : _registration(registration)
    {
    }

    Page *show(PageHandler *handler);

    ~UpdateUserPage(){};
};

class DeleteUserPage : public Page
{
private:
    Registration _registration;

public:
    DeleteUserPage(const Registration &registration) : _registration(registration)
    {
    }

    Page *show(PageHandler *handler);

    ~DeleteUserPage(){};
};

template <class C>
class ItemsMenuPage : public Page
{
private:
    std::string _action;

public:
    ItemsMenuPage(const std::string &action) : _action(action)
    {
    }

    Page *show(PageHandler *handler);

    ~ItemsMenuPage(){};
};

template <class C>
Page *ItemsMenuPage<C>::show(PageHandler *handler)
{
    handler->print(_action + " items options");
    handler->print("");

    const std::vector<std::string> options{
        "Play",
        "Room",
        "Session",
        "Quit"};

    while (true)
    {
        handler->print("");
        unsigned int option = handler->renderMenu(options);

        switch (option)
        {
        case 0:
            return nullptr;
        case 1:
        case 2:
        case 3:
            return new C;
        default:
            handler->clearScreen();
            handler->print("Invalid Option " + std::to_string(option));
            handler->print("");
            break;
        }
    }
}

#endif
