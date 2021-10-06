#include <sstream>

#include "ParticipantHandler.h"
#include "../db/DBHandler.h"

SQLResult ParticipantHandler::create(const Participant &participant)
{
    std::stringstream query;

    query << "INSERT INTO Participants (registration, first_name, last_name, email, phone_number, password, role) VALUES ("
          << '\'' << participant.getRegistration().get() << "\',"
          << '\'' << participant.getFirstName().get() << "\',"
          << '\'' << participant.getLastName().get() << "\',"
          << '\'' << participant.getEmail().get() << "\',"
          << '\'' << participant.getPhoneNumber().get() << "\',"
          << '\'' << participant.getPassword().get() << "\',"
          << '\'' << participant.getRole().get() << "\');";

    return DBHandler::getInstance()->execute(query);
}

SQLResult ParticipantHandler::remove(const Registration &registration)
{
    std::stringstream query;

    query << "DELETE FROM Participants WHERE registration="
          << '\'' << registration.get() << "\';";

    return DBHandler::getInstance()->execute(query);
}

SQLResult ParticipantHandler::search(const Registration &registration)
{
    std::stringstream query;

    query << "SELECT * FROM Participants WHERE registration='" << registration.get() << "';";

    return DBHandler::getInstance()->execute(query);
}
SQLResult ParticipantHandler::list()
{
    std::stringstream query;

    query << "SELECT * FROM Participants;";

    return DBHandler::getInstance()->execute(query);
}

SQLResult ParticipantHandler::list()
{
    std::stringstream query;

    query << "SELECT * FROM Participants;";

    return DBHandler::getInstance()->execute(query);
}

std::map<std::string, std::string> ParticipantHandler::authenticate(const Registration &registration, const Password &password)
{
    SQLResult result = search(registration);

    if (result.rows.size() > 0)
    {
        for (auto &row : result.rows)
        {
            if (row["registration"] == registration.get())
            {
                return row["password"] == password.get() ? row : std::map<std::string, std::string>{};
            }
        }
    }

    // Not found. Returns empty map
    return std::map<std::string, std::string>{};
}

SQLResult ParticipantHandler::update(const Participant &participant)
{
    std::stringstream query;

    query << "UPDATE Participants SET"
          << " first_name = '"
          << participant.getFirstName().get()
          << "', last_name = '"
          << participant.getLastName().get()
          << "', email = '"
          << participant.getEmail().get()
          << "', phone_number = '"
          << participant.getPhoneNumber().get()
          << "', password = '"
          << participant.getPassword().get()
          << "', role = '"
          << participant.getRole().get()
          << "' WHERE registration = '" << participant.getRegistration().get() << '\'';

    return DBHandler::getInstance()->execute(query);
}