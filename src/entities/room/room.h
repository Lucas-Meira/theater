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

    Room(std::string id, std::string name, uint16_t capacity)
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
    
    void setId(std::string id)
    {
        _id = IdCode(id);
    }

    IdCode getId()
    {
        return _id;
    }

    void setName(Name name)
    {
        _name = name;
    }
    
    void setName(std::string name)
    {
        _name = Name(name);
    }

    Name getName()
    {
        return _name;
    }

    void setCapacity(Capacity capacity)
    {
        _capacity = capacity;
    }
    
    void setCapacity(uint16_t capacity)
    {
        _capacity = Capacity(capacity);
    }

    Capacity getCapacity()
    {
        return _capacity;
    }
};

#endif