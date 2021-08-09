#ifndef ROOM_H
#define ROOM_H

#include "../../domains/domains.h"

class Room
{
private:
    IdCode _id;
    Name _name;
    Capacity _capacity;

public:
    Room(IdCode id, Name name, Capacity capacity)
    {
        setId(id);
        setName(name);
        setCapacity(capacity);
    }

    Room() {}

    void setId(IdCode id)
    {
        _id = id;
    }

    IdCode getId()
    {
        return _id;
    }

    void setName(Name name)
    {
        _name = name;
    }

    Name getName()
    {
        return _name;
    }

    void setCapacity(Capacity capacity)
    {
        _capacity = capacity;
    }

    Capacity getCapacity()
    {
        return _capacity;
    }
};

#endif