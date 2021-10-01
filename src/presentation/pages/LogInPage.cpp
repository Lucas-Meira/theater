#include "../Pages.h"
#include "../../domains/domains.h"
#include "../../entities/entities.h"

Page *LogInPage::show(PageHandler *handler)
{
    handler->print("Login");
    handler->print("");

    Registration registration;
    Password password;

    handler->print("Registration id: ");
    std::string reg = handler->readInput();
    handler->print("Password: ");
    std::string pw = handler->readInput();

    try
    {
        registration = Registration(reg);
        password = Password(pw);
    }
    catch (const std::invalid_argument &)
    {
        handler->print("Wrong registration id or password. Try again? [Yy/Nn] ");
        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new InitPage;
        }
        return new LogInPage;
    }

    std::map<std::string, std::string> user = handler->getServices()->getParticipantHandler()->authenticate(registration, password);

    if (user.empty())
    {
        handler->print("Wrong registration id or password. Try again? [Yy/Nn] ");
        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new InitPage;
        }
        return new LogInPage;
    }

    return new AuthenticatedInitPage(Participant(user["registration"], user["first_name"], user["last_name"],
                                                 user["email"], user["phone_number"], user["password"], user["role"]));
}