#ifndef PATICIPANT_INTERFACE_H
#define PATICIPANT_INTERFACE_H

#include "../../domains/domains.h"
#include "../../entities/entities.h"

class ParticipantInterface
{
public:
    virtual bool create(const Participant &participant) = 0;
    virtual bool unregister(const Participant &participant) = 0;
    virtual bool search(const Participant &participant) = 0;
    virtual bool search(const Registration &registration) = 0;
    virtual bool search(const Name &firstName) = 0;
    virtual bool authenticate(const Registration &registration, const Password &password) = 0;
};

#endif