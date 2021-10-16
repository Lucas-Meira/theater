#ifndef PLAY_HANDLER_H
#define PLAY_HANDLER_H

#include "../interfaces/PlayInterface.h"

class PlayHandler : public PlayInterface
{
public:
    SQLResult create(const Play &play);
    SQLResult remove(const IdCode &id);
    SQLResult search(const IdCode &id);
    SQLResult update(const Play &play);
    SQLResult list();
};
#endif
