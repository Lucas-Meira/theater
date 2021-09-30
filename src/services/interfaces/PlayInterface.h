#ifndef PLAY_INTERFACE_H
#define PLAY_INTERFACE_H

#include "../db/DBHandler.h"

#include "../../domains/domains.h"
#include "../../entities/entities.h"

class PlayInterface
{
public:
    virtual SQLResult create(const Play &play) = 0;
    virtual SQLResult remove(const IdCode &id) = 0;
    virtual SQLResult search(const IdCode &id) = 0;
    virtual SQLResult list() = 0;
    virtual SQLResult update(const Play &play) = 0;
};

#endif
