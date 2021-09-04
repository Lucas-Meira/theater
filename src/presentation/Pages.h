#ifndef PAGES_H
#define PAGES_H

#include "PageHandler.h"

class Page
{
public:
    virtual Page *show(PageHandler *handler) = 0;
};

class InitPage : public Page
{
public:
    Page *show(PageHandler *handler);
};

#endif