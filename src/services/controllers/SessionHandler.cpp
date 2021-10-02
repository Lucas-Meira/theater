#include <sstream>

#include "SessionHandler.h"
#include "../db/DBHandler.h"

SQLResult SessionHandler::create(const Session &session, const IdCode &playId, const IdCode &roomId)
{
    std::stringstream query;

    query << "INSERT INTO Sessions (id_sessions, date, time, id_plays_id, id_rooms_id) VALUES ("
          << '\'' << session.getId().get() << "\',"
          << '\'' << session.getDate().get() << "\',"
          << '\'' << session.getTime().get() << "\',"
          << '\'' << playId.get() << "\',"
          << '\'' << roomId.get() << "\');";

    return DBHandler::getInstance()->execute(query);
}

SQLResult SessionHandler::remove(const IdCode &id)
{
    std::stringstream query;

    query << "DELETE FROM Sessions WHERE id_sessions="
          << '\'' << id.get() << "\';";

    return DBHandler::getInstance()->execute(query);
}

SQLResult SessionHandler::search(const IdCode &id)
{
    std::stringstream query;

    query << "SELECT id_sessions, date, time, id_plays_id, id_rooms_id  FROM Sessions WHERE id_sessions='" << id.get() << "';";

    return DBHandler::getInstance()->execute(query);
}

SQLResult SessionHandler::list()
{
    std::stringstream query;

    query << "SELECT * FROM Sessions;";

    return DBHandler::getInstance()->execute(query);
}

SQLResult SessionHandler::update(const Session &session, const IdCode &playId, const IdCode &roomId)

{
    std::stringstream query;

    query << "UPDATE Sessions SET"
          << " date = '"
          << session.getDate().get()
          << "', time = '"
          << session.getTime().get()
          << "', id_plays_id = '"
          << playId.get()
          << "', id_rooms_id = '"
          << roomId.get()
          << "' WHERE id_sessions = '" << session.getId().get() << "\';";

    return DBHandler::getInstance()->execute(query);
}
