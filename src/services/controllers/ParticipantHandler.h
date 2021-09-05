#ifndef PARTICIPANT_HANDLER_H
#define PARTICIPANT_HANDLER_H

#include "../interfaces/ParticipantInterface.h"

class ParticipantHandler : public ParticipantInterface
{
public:
    bool create(const Participant &participant);
    bool unregister(const Participant &participant);
    bool search(const Participant &participant);
    bool search(const Registration &registration);
    bool search(const Name &firstName);
    bool authenticate(const Registration &registration, const Password &password);
};
#endif