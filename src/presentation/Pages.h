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

#endif