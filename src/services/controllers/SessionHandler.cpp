#include <sstream>

#include "SessionHandler.h"
#include "../db/DBHandler.h"

SQLResult SessionHandler::create(const Session &session, const Play &play, const Room &room)
{
    std::stringstream query;

    query << "INSERT INTO Sessions (id_sessions, date, time, id_Plays_id, id_rooms_id) VALUES ("
          << '\'' << session.getId().get() << "\',"
          << '\'' << session.getDate().get() << "\',"
          << '\'' << session.getTime().get() << "\',"
          << '\'' << play.getId().get() << "\',"
          << '\'' << room.getId().get() << "\');";

    return DBHandler::getInstance()->execute(query);
}

SQLResult SessionHandler::remove(const Session &session)
{
    std::stringstream query;

    query << "DELETE FROM Sessions WHERE id_sessions="
          << '\'' << session.getId().get() << "\';";

    return DBHandler::getInstance()->execute(query);
}

SQLResult SessionHandler::search(const IdCode &id)
{
    std::stringstream query;

    query << "SELECT id_sessions, date, time, id_Plays_id, id_rooms_id  FROM Sessions WHERE id_sessions='" << id.get() << "';";

    return DBHandler::getInstance()->execute(query);
}

SQLResult SessionHandler::update(const Session &session,  const Play &play, const Room &room)
{
    std::stringstream query;

    query << "UPDATE Sessions SET"
          << "date = '"
          << session.getDate().get()
          << "time = '"
          << session.getTime().get()
          << "id_Plays_id = '"
          << play.getId().get()
          << "' id_rooms_id = '"
          << room.getId().get()
          << "' WHERE id_sessions = '" << session.getId().get() << '\'';

    return DBHandler::getInstance()->execute(query);
}