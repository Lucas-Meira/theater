#ifndef SERVICES_H
#define SERVICES_H

#include "controllers/controllers.h"

#include "interfaces/ParticipantInterface.h"

class ServicesInterface
{
private:
    ParticipantInterface *_participantHandler;

public:
    ServicesInterface(ParticipantInterface *participantHandler) : _participantHandler(participantHandler)
    {
    }

    ParticipantInterface *getParticipantHandler() const { return _participantHandler; }
};

#endif