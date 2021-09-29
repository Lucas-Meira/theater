#include "../Pages.h"
#include "../../domains/domains.h"
#include "../../entities/entities.h"

Page *RegisterItemPage::show(PageHandler *handler)
{
    std::string input;

    Registration registration;
    Name firstName;
    Name lastName;
    Email email;
    PhoneNumber phoneNumber;
    Password password;
    Role role;

    while (true)
    {
        handler->print("Register a new user");
        handler->print("");

        while (true)
        {
            handler->print("Enter registration id: ");
            input = handler->readInput();

            try
            {
                registration = Registration(input);
                break;
            }
            catch (const std::invalid_argument &)
            {
                handler->print("Invalid input. Try again? [Yy/Nn] ");
                int option = getch();
                bool tryAgain = option == 'Y' || option == 'y';

                if (!tryAgain)
                {
                    return new InitPage;
                }
                handler->clearScreen();
            }
        }

        while (true)
        {
            handler->print("Enter first name: ");
            input = handler->readInput();

            try
            {
                firstName = Name(input);
                break;
            }
            catch (const std::invalid_argument &)
            {
                handler->print("Invalid input. Try again? [Yy/Nn] ");
                int option = getch();
                bool tryAgain = option == 'Y' || option == 'y';

                if (!tryAgain)
                {
                    return new InitPage;
                }
                handler->clearScreen();
            }
        }

        while (true)
        {
            handler->print("Enter last name: ");
            input = handler->readInput();

            try
            {
                lastName = Name(input);
                break;
            }
            catch (const std::invalid_argument &)
            {
                handler->print("Invalid input. Try again? [Yy/Nn]");

                int option = getch();
                bool tryAgain = option == 'Y' || option == 'y';

                if (!tryAgain)
                {
                    return new InitPage;
                }
                handler->clearScreen();
            }
        }

        while (true)
        {
            handler->print("Enter email: ");
            input = handler->readInput();

            try
            {
                email = Email(input);
                break;
            }
            catch (const std::invalid_argument &)
            {
                handler->print("Invalid input. Try again? [Yy/Nn]");
                int option = getch();
                bool tryAgain = option == 'Y' || option == 'y';

                if (!tryAgain)
                {
                    return new InitPage;
                }
                handler->clearScreen();
            }
        }

        while (true)
        {
            handler->print("Enter phone number: ");
            input = handler->readInput();

            try
            {
                phoneNumber = PhoneNumber(input);
                break;
            }
            catch (const std::invalid_argument &)
            {
                handler->print("Invalid input. Try again? [Yy/Nn]");
                int option = getch();
                bool tryAgain = option == 'Y' || option == 'y';

                if (!tryAgain)
                {
                    return new InitPage;
                }
                handler->clearScreen();
            }
        }

        while (true)
        {
            handler->print("Enter password: ");
            input = handler->readInput();

            try
            {
                password = Password(input);
                break;
            }
            catch (const std::invalid_argument &)
            {
                handler->print("Invalid input. Try again? [Yy/Nn]");
                int option = getch();
                bool tryAgain = option == 'Y' || option == 'y';

                if (!tryAgain)
                {
                    return new InitPage;
                }
                handler->clearScreen();
            }
        }

        while (true)
        {
            handler->print("Enter role: ");
            input = handler->readInput();

            try
            {
                role = Role(input);
                break;
            }
            catch (const std::invalid_argument &)
            {
                handler->print("Invalid input. Try again? [Yy/Nn]");
                int option = getch();
                bool tryAgain = option == 'Y' || option == 'y';

                if (!tryAgain)
                {
                    return new InitPage;
                }
                handler->clearScreen();
            }
        }

        handler->clearScreen();

        handler->print("Please check the info provided");
        handler->print("");
        handler->print("Registration: " + registration.get());
        handler->print("First Name: " + firstName.get());
        handler->print("Last Name: " + lastName.get());
        handler->print("Email: " + email.get());
        handler->print("Phone Number: " + phoneNumber.get());
        handler->print("Password: " + password.get());
        handler->print("Role: " + role.get());
        handler->print("Is the info provided correct? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'N' || option == 'n';

        if (!tryAgain)
        {
            break;
        }

        handler->clearScreen();
    }

    ServicesInterface *services = handler->getServices();

    SQLResult result = services->getParticipantHandler()->create(Participant(registration, firstName, lastName, email, phoneNumber, password, role));

    if (result.status != SQLResult::SUCCESS)
    {
        handler->clearScreen();

        handler->print("Failed to create user.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new InitPage;
        }

        return new RegisterItemPage;
    }

    return new InitPage;
}