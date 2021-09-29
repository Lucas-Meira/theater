#ifndef ROOM_H
#define ROOM_H

#include "../../domains/domains.h"

///
/// This class stores all the information of the room of the theater.
/// Types of information:
/// - Identification code
/// - Name
/// - Capacity of the room
///

class Room
{
private:
    IdCode _id;
    Name _name;
    Capacity _capacity;
    std::vector<IdCode> _sessions;

public:
    ///
    /// Calls all the methods set for the objects of the attributes of class Room, if its objects is already created.
    /// @param id
    /// @param name
    /// @param capacity
    ///

    Room(IdCode id, Name name, Capacity capacity)
    {
        setId(id);
        setName(name);
        setCapacity(capacity);
    }

    ///
    /// Calls all the methods set for the objects of the attributes of class Room.
    /// @param id
    /// @param name
    /// @param capacity
    ///

    Room(const std::string &id, const std::string &name, const uint16_t &capacity)
    {
        setId(id);
        setName(name);
        setCapacity(capacity);
    }

    ///
    /// Creates an instance of the classRoom.
    ///

    Room() {}

    ///
    /// Stores an already created object of class IdCode.
    /// @param id
    ///

    void setId(const IdCode &id)
    {
        _id = id;
    }

    ///
    /// Creates and stores the object of the class IdCode.
    /// @param id
    ///

    void setId(const std::string &id)
    {
        _id = IdCode(id);
    }

    ///
    /// Returns the stored object of the class IdCode.
    /// @return _id
    ///

    IdCode getId() const
    {
        return _id;
    }

    ///
    /// Stores an already created object of class Name.
    /// @param name
    ///

    void setName(const Name &name)
    {
        _name = name;
    }

    ///
    /// Creates and stores the object of the class Name.
    /// @param name
    ///

    void setName(const std::string &name)
    {
        _name = Name(name);
    }

    ///
    /// Returns the stored object of the class Name.
    /// @return _name
    ///

    Name getName() const
    {
        return _name;
    }

    ///
    /// Stores an already created object of class Capacity.
    /// @param capacity
    ///

    void setCapacity(const Capacity &capacity)
    {
        _capacity = capacity;
    }

    ///
    /// Creates and stores the object of the class Capacity.
    /// @param capacity
    ///

    void setCapacity(const uint16_t &capacity)
    {
        _capacity = Capacity(capacity);
    }

    ///
    /// Returns the stored object of the class Capacity.
    /// @return _capacity
    ///

    Capacity getCapacity() const
    {
        return _capacity;
    }

    bool addSession(const IdCode &id)
    {
        _sessions.push_back(id);

        return true;
    }

    std::vector<IdCode> getSessions()
    {
        return _sessions;
    }
};

#endif