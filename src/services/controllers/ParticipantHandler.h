#ifndef PARTICIPANT_HANDLER_H
#define PARTICIPANT_HANDLER_H

#include "../interfaces/ParticipantInterface.h"

class ParticipantHandler : public ParticipantInterface
{
public:
    SQLResult create(const Participant &participant);
    SQLResult remove(const Registration &registration);
    SQLResult search(const Registration &registration);
    SQLResult update(const Participant &participant);
    std::map<std::string, std::string> authenticate(const Registration &registration, const Password &password);
};
#endif