#include <sstream>

#include "PlayHandler.h"
#include "../db/DBHandler.h"

SQLResult PlayHandler::create(const Play &play)
{
    std::stringstream query;

    query << "INSERT INTO Plays (id_plays, name, rating, type) VALUES ("
          << '\'' << play.getId().get() << "\',"
          << '\'' << play.getName().get() << "\',"
          << '\'' << play.getRating().get() << "\',"
          << '\'' << play.getType().get() << "\');";

    return DBHandler::getInstance()->execute(query);
}

SQLResult PlayHandler::remove(const Play &play)
{
    std::stringstream query;

    query << "DELETE FROM Plays WHERE id_plays="
          << '\'' << play.getId().get() << "\';";

    return DBHandler::getInstance()->execute(query);
}

SQLResult PlayHandler::search(const IdCode &id)
{
    std::stringstream query;

    query << "SELECT id_plays, name, rating, type  FROM Plays WHERE id_plays='" << id.get() << "';";

    return DBHandler::getInstance()->execute(query);
}

SQLResult PlayHandler::update(const Play &play)
{
    std::stringstream query;

    query << "UPDATE Plays SET"
          << "name = '"
          << play.getName().get()
          << "' rating = '"
          << play.getRating().get()
          << "' type = '"
          << play.getType().get()
          << "' WHERE id_plays = '" << play.getId().get() << '\'';

    return DBHandler::getInstance()->execute(query);
}