#ifndef PARTICIPANT_HANDLER_H
#define PARTICIPANT_HANDLER_H

#include "../interfaces/ParticipantInterface.h"

class ParticipantHandler : public ParticipantInterface
{
public:
    SQLResult create(const Participant &participant);
    SQLResult remove(const Registration &registration);
    SQLResult search(const Registration &registration);
    SQLResult list();
    SQLResult update(const Participant &participant);
    SQLResult updatePlay(const Registration &registration, const IdCode &playId);
    std::map<std::string, std::string> authenticate(const Registration &registration, const Password &password);
};
#endif
