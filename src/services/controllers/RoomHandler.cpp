#include <sstream>

#include "RoomHandler.h"
#include "../db/DBHandler.h"

SQLResult RoomHandler::create(const Room &room)
{
    std::stringstream query;

    query << "INSERT INTO Rooms (id_rooms, name, capacities) VALUES ("
          << '\'' << room.getId().get() << "\',"
          << '\'' << room.getName().get() << "\',"
          << '\'' << room.getCapacity().get() << "\');";

    return DBHandler::getInstance()->execute(query);
}

SQLResult RoomHandler::remove(const IdCode &id)
{
    std::stringstream query;

    query << "DELETE FROM Rooms WHERE id_rooms="
          << '\'' << id.get() << "\';";

    return DBHandler::getInstance()->execute(query);
}

SQLResult RoomHandler::search(const IdCode &id)
{
    std::stringstream query;

    query << "SELECT id_rooms, name, rating, type  FROM Rooms WHERE id_rooms='" << id.get() << "';";

    return DBHandler::getInstance()->execute(query);
}

SQLResult RoomHandler::update(const Room &room)
{
    std::stringstream query;

    query << "UPDATE Rooms SET"
          << " name = '"
          << room.getName().get()
          << "' capacities = '"
          << room.getCapacity().get()
          << "' WHERE id_rooms = '" << room.getId().get() << '\'';

    return DBHandler::getInstance()->execute(query);
}
