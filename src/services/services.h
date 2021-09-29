#ifndef SERVICES_H
#define SERVICES_H

#include "controllers/controllers.h"

#include "interfaces/ParticipantInterface.h"
#include "interfaces/PlayInterface.h"
#include "interfaces/RoomInterface.h"
#include "interfaces/SessionInterface.h"

class ServicesInterface
{
private:
    ParticipantInterface *_participantHandler;
    PlayInterface *_playHandler;
    RoomInterface *_roomHandler;
    SessionInterface *_sessionHandler;

public:
    ServicesInterface(ParticipantInterface *participantHandler,
                      PlayInterface *playHandler,
                      RoomInterface *roomHandler,
                      SessionInterface *sessionHandler) : _participantHandler(participantHandler),
                                                          _playHandler(playHandler),
                                                          _roomHandler(roomHandler),
                                                          _sessionHandler(sessionHandler)
    {
    }

    ParticipantInterface *getParticipantHandler() const { return _participantHandler; }
    PlayInterface *getPlayHandler() const { return _playHandler; }
    RoomInterface *getRoomHandler() const { return _roomHandler; }
    SessionInterface *getSessionHandler() const { return _sessionHandler; }
};

#endif