#ifndef SESSION_INTERFACE_H
#define SESSION_INTERFACE_H

#include "../db/DBHandler.h"

#include "../../domains/domains.h"
#include "../../entities/entities.h"

class SessionInterface
{
public:
    virtual SQLResult create(const Session &session, const IdCode &playId, const IdCode &roomId) = 0;
    virtual SQLResult remove(const IdCode &id) = 0;
    virtual SQLResult search(const IdCode &id) = 0;
    virtual SQLResult list() = 0;
    virtual SQLResult update(const Session &session, const Play &play, const Room &room) = 0;
};

#endif
