#include <sstream>

#include "ParticipantHandler.h"
#include "../db/DBHandler.h"

SQLResult ParticipantHandler::create(const Participant &participant)
{
    std::stringstream query;

    query << "INSERT INTO Participants (registration, first_name, last_name, email, phone_number, password, role) VALUES ("
          << '\'' << participant.getRegistration() << "\',"
          << '\'' << participant.getFirstName() << "\',"
          << '\'' << participant.getLastName() << "\',"
          << '\'' << participant.getEmail() << "\',"
          << '\'' << participant.getPhoneNumber() << "\',"
          << '\'' << participant.getPassword() << "\',"
          << '\'' << participant.getRole() << "\');";

    DBHandler *dbHandler = DBHandler::getInstance();

    return dbHandler->execute(query);
}

SQLResult ParticipantHandler::unregister(const Participant &participant)
{
    std::stringstream query;

    query << "DELETE FROM Participant WHERE registration="
          << '\'' << participant.getRegistration() << "\';";

    DBHandler *dbHandler = DBHandler::getInstance();

    return dbHandler->execute(query);
}

bool ParticipantHandler::search(const Participant &participant)
{
    return false;
}
bool ParticipantHandler::search(const Registration &registration)
{
    return false;
}
bool ParticipantHandler::search(const Name &firstName)
{
    return false;
}
std::map<std::string, std::string> ParticipantHandler::authenticate(const Registration &registration, const Password &password)
{
    std::stringstream query;

    query << "SELECT first_name, last_name, registration, password FROM Participants WHERE registration='" << registration.get() << "';";

    SQLResult result = DBHandler::getInstance()->execute(query);

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

    return std::map<std::string, std::string>{};
}