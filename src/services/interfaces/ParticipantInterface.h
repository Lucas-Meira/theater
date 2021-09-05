#ifndef PATICIPANT_INTERFACE_H
#define PATICIPANT_INTERFACE_H

#include "../db/DBHandler.h"

#include "../../domains/domains.h"
#include "../../entities/entities.h"

class ParticipantInterface
{
public:
    virtual SQLResult create(const Participant &participant) = 0;
    virtual SQLResult unregister(const Participant &participant) = 0;
    virtual bool search(const Participant &participant) = 0;
    virtual bool search(const Registration &registration) = 0;
    virtual bool search(const Name &firstName) = 0;
    virtual std::map<std::string, std::string> authenticate(const Registration &registration, const Password &password) = 0;
};

#endif