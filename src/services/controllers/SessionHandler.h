#ifndef SESSION_HANDLER_H
#define SESSION_HANDLER_H

#include "../interfaces/SessionInterface.h"

class SessionHandler : public SessionInterface
{
public:
    SQLResult create(const Session &session, const Play &play, const Room &room);
    SQLResult remove(const Session &session);
    SQLResult search(const IdCode &id);
    SQLResult update(const Session &session, const Play &play, const Room &room);
};
#endif