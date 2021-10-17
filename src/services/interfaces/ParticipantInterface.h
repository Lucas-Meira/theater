#ifndef PATICIPANT_INTERFACE_H
#define PATICIPANT_INTERFACE_H

#include "../db/DBHandler.h"

#include "../../domains/domains.h"
#include "../../entities/entities.h"

class ParticipantInterface
{
public:
    virtual SQLResult create(const Participant &participant) = 0;
    virtual SQLResult remove(const Registration &registration) = 0;
    virtual SQLResult search(const Registration &registration) = 0;
    virtual SQLResult list() = 0;
    virtual SQLResult update(const Participant &participant) = 0;
    virtual SQLResult updatePlay(const Registration &registration, const IdCode &playId) = 0;
    virtual std::map<std::string, std::string> authenticate(const Registration &registration, const Password &password) = 0;
};

#endif