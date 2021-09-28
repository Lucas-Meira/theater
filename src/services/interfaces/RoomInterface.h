#ifndef ROOM_INTERFACE_H
#define ROOM_INTERFACE_H

#include "../db/DBHandler.h"

#include "../../domains/domains.h"
#include "../../entities/entities.h"

class RoomInterface
{
public:
    virtual SQLResult create(const Room &room) = 0;
    virtual SQLResult remove(const Room &room) = 0;
    virtual SQLResult search(const IdCode &id) = 0;
    virtual SQLResult update(const Room &room) = 0;
};

#endif