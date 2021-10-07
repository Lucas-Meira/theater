#ifndef ROOM_HANDLER_H
#define ROOM_HANDLER_H

#include "../interfaces/RoomInterface.h"

class RoomHandler : public RoomInterface
{
public:
    SQLResult create(const Room &room);
    SQLResult remove(const IdCode &id);
    SQLResult search(const IdCode &id);
    SQLResult list();
    SQLResult update(const Room &room);

};
#endif
