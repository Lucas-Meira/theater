#ifndef SESSION_INTERFACE_H
#define SESSSION_INTERFACE_H

#include "../db/DBHandler.h"

#include "../../domains/domains.h"
#include "../../entities/entities.h"

class SessionInterface
{
public:
    virtual SQLResult create(const Session &session) = 0;
    virtual SQLResult remove(const Session &session) = 0;
    virtual SQLResult search(const IdCode &id) = 0;
    virtual SQLResult update(const Session &session) = 0;
};

#endif