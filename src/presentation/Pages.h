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
    Name _firstName;
    Name _lastName;

public:
    AuthenticatedInitPage(const Name &firstName, const Name &lastName) : _firstName(firstName), _lastName(lastName)
    {
    }

    Page *
    show(PageHandler *handler);

    ~AuthenticatedInitPage(){};
};

#endif
