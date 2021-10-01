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
    Participant _user;

public:
    AuthenticatedInitPage(const Participant &user) : _user(user)
    {
    }

    Page *show(PageHandler *handler);

    ~AuthenticatedInitPage(){};
};

class UpdateUserPage : public Page
{
private:
    Participant _user;

public:
    UpdateUserPage(const Participant &user) : _user(user)
    {
    }

    Page *show(PageHandler *handler);

    ~UpdateUserPage(){};
};

class DeleteUserPage : public Page
{
private:
    Participant _user;

public:
    DeleteUserPage(const Participant &user) : _user(user)
    {
    }

    Page *show(PageHandler *handler);

    ~DeleteUserPage(){};
};

class ItemsMenuPage : public Page
{
private:
    Participant _user;
    std::string _action;

    Page *_handleList(PageHandler *handler, unsigned int option);
    Page *_handleInclude(PageHandler *handler, unsigned int option);
    Page *_handleDelete(PageHandler *handler, unsigned int option);
    Page *_handleEdit(PageHandler *handler, unsigned int option);
    Page *_handleView(PageHandler *handler, unsigned int option);

public:
    ItemsMenuPage(const Participant &user, const std::string &action) : _user(user), _action(action)
    {
    }

    Page *show(PageHandler *handler);

    ~ItemsMenuPage(){};
};

class IncludeItemsPage : public Page
{
private:
    Participant _user;
    std::string _entityToInclude;

    Page *_includePlay(PageHandler *handler);
    Page *_includeRoom(PageHandler *handler);
    Page *_includeSession(PageHandler *handler);

public:
    IncludeItemsPage(const Participant &user, const std::string &entityToInclude) : _user(user), _entityToInclude(entityToInclude)
    {
    }

    Page *show(PageHandler *handler);

    ~IncludeItemsPage(){};
};

class DeleteItemsPage : public Page
{
private:
    Participant _user;
    std::string _entityToDelete;

    Page *_deletePlay(PageHandler *handler);
    Page *_deleteRoom(PageHandler *handler);
    Page *_deleteSession(PageHandler *handler);

public:
    DeleteItemsPage(const Participant &user, const std::string &entityToDelete) : _user(user), _entityToDelete(entityToDelete)
    {
    }

    Page *show(PageHandler *handler);

    ~DeleteItemsPage(){};
};

#endif
