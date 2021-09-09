#ifndef PARTICIPANT_HANDLER_H
#define PARTICIPANT_HANDLER_H

#include "../interfaces/ParticipantInterface.h"

class ParticipantHandler : public ParticipantInterface
{
public:
    SQLResult create(const Participant &participant);
    SQLResult unregister(const Participant &participant);
    bool search(const Participant &participant);
    bool search(const Registration &registration);
    bool search(const Name &firstName);
    bool update(const Participant &participant);
    std::map<std::string, std::string> authenticate(const Registration &registration, const Password &password);
};
#endif