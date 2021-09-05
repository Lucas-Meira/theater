#include <sstream>

#include "ParticipantHandler.h"
#include "../db/DBHandler.h"

bool ParticipantHandler::create(const Participant &participant)
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

bool ParticipantHandler::unregister(const Participant &participant)
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
bool ParticipantHandler::authenticate(const Registration &registration, const Password &password)
{
    return false;
}