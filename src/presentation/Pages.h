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
private:
    Participant _user;
    std::string _entityToList;

    Page *_listPlays(PageHandler *handler);
    Page *_listRooms(PageHandler *handler);
    Page *_listSessions(PageHandler *handler);

    bool _isLoggedIn;

public:
    ListItemsPage(const std::string &entityToList) : _entityToList(entityToList)
    {
        _isLoggedIn = false;
    }

    ListItemsPage(const Participant &user, const std::string &entityToList) : _user(user), _entityToList(entityToList)
    {
        _isLoggedIn = true;
    }

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

    bool _isLoggedIn;

public:
    ItemsMenuPage(const std::string &action) : _action(action)
    {
        _isLoggedIn = false;
    }

    ItemsMenuPage(const Participant &user, const std::string &action) : _user(user), _action(action)
    {
        _isLoggedIn = true;
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

class EditItemsPage : public Page
{
private:
    Participant _user;
    std::string _entityToEdit;

    Page *_editPlay(PageHandler *handler);
    Page *_editRoom(PageHandler *handler);
    Page *_editSession(PageHandler *handler);

public:
    EditItemsPage(const Participant &user, const std::string &entityToEdit) : _user(user), _entityToEdit(entityToEdit)
    {
    }

    Page *show(PageHandler *handler);

    ~EditItemsPage(){};
};

class ViewItemsPage : public Page
{
private:
    Participant _user;
    std::string _entityToView;

    Page *_viewPlays(PageHandler *handler);
    Page *_viewRooms(PageHandler *handler);
    Page *_viewSessions(PageHandler *handler);

public:
    ViewItemsPage(const Participant &user, const std::string &entityToView) : _user(user), _entityToView(entityToView)
    {
    }

    Page *show(PageHandler *handler);

    ~ViewItemsPage(){};
};

#endif
