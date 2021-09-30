#ifndef SESSION_HANDLER_H
#define SESSION_HANDLER_H

#include "../interfaces/SessionInterface.h"

class SessionHandler : public SessionInterface
{
public:
    SQLResult create(const Session &session, const IdCode &playId, const IdCode &roomId);
    SQLResult remove(const IdCode &id);
    SQLResult search(const IdCode &id);
    SQLResult update(const Session &session, const IdCode &playId, const IdCode &roomId);
};
#endif
