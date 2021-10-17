#include "../../Pages.h"

Page *UpdateUserPage::show(PageHandler *handler)
{
    handler->print("Update User Page");

    SQLResult result = handler->getServices()->getParticipantHandler()->search(_user.getRegistration());

    if (result.rows.empty())
    {
        handler->print("Something went wrong!");

        return new InitPage;
    }

    auto user = result.rows[0];

    Registration registration = Registration(user["registration"]);
    Name firstName;
    Name lastName;
    Email email;
    PhoneNumber phoneNumber;
    Password password;
    Role role;

    std::string input;

    while (true)
    {
        handler->print("Update First Name? " + user["first_name"] + " [Yy/Nn]");

        int option = getch();
        bool update = option == 'Y' || option == 'y';

        if (!update)
        {
            firstName = Name(user["first_name"]);
            break;
        }

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
                return new AuthenticatedInitPage(_user);
            }
            handler->clearLines(3);
        }
    }

    while (true)
    {
        handler->print("Update Last Name? " + user["last_name"] + " [Yy/Nn]");

        int option = getch();
        bool update = option == 'Y' || option == 'y';

        if (!update)
        {
            lastName = Name(user["last_name"]);
            break;
        }

        handler->print("Enter last name: ");
        input = handler->readInput();

        try
        {
            lastName = Name(input);
            break;
        }
        catch (const std::invalid_argument &)
        {
            handler->print("Invalid input. Try again? [Yy/Nn] ");
            int option = getch();
            bool tryAgain = option == 'Y' || option == 'y';

            if (!tryAgain)
            {
                return new AuthenticatedInitPage(_user);
            }
            handler->clearLines(3);
        }
    }

    while (true)
    {
        handler->print("Update Email? " + user["email"] + " [Yy/Nn]");

        int option = getch();
        bool update = option == 'Y' || option == 'y';

        if (!update)
        {
            email = Email(user["email"]);
            break;
        }

        handler->print("Enter email: ");
        input = handler->readInput();

        try
        {
            email = Email(input);
            break;
        }
        catch (const std::invalid_argument &)
        {
            handler->print("Invalid input. Try again? [Yy/Nn] ");
            int option = getch();
            bool tryAgain = option == 'Y' || option == 'y';

            if (!tryAgain)
            {
                return new AuthenticatedInitPage(_user);
            }
            handler->clearLines(3);
        }
    }

    while (true)
    {
        handler->print("Update Phone Number? " + user["phone_number"] + " [Yy/Nn]");

        int option = getch();
        bool update = option == 'Y' || option == 'y';

        if (!update)
        {
            phoneNumber = PhoneNumber(user["phone_number"]);
            break;
        }

        handler->print("Enter phone number: ");
        input = handler->readInput();

        try
        {
            phoneNumber = PhoneNumber(input);
            break;
        }
        catch (const std::invalid_argument &)
        {
            handler->print("Invalid input. Try again? [Yy/Nn] ");
            int option = getch();
            bool tryAgain = option == 'Y' || option == 'y';

            if (!tryAgain)
            {
                return new AuthenticatedInitPage(_user);
            }
            handler->clearLines(3);
        }
    }

    while (true)
    {
        handler->print("Update Password? [Yy/Nn]");

        int option = getch();
        bool update = option == 'Y' || option == 'y';

        if (!update)
        {
            password = Password(user["password"]);
            break;
        }

        handler->print("Enter password: ");
        input = handler->readInput();

        try
        {
            password = Password(input);
            break;
        }
        catch (const std::invalid_argument &)
        {
            handler->print("Invalid input. Try again? [Yy/Nn] ");
            int option = getch();
            bool tryAgain = option == 'Y' || option == 'y';

            if (!tryAgain)
            {
                return new AuthenticatedInitPage(_user);
            }
            handler->clearLines(3);
        }
    }

    while (true)
    {
        handler->print("Update Role? " + user["role"] + " [Yy/Nn]");

        int option = getch();
        bool update = option == 'Y' || option == 'y';

        if (!update)
        {
            role = Role(user["role"]);
            break;
        }

        handler->print("Enter role: ");
        input = handler->readInput();

        try
        {
            role = Role(input);
            break;
        }
        catch (const std::invalid_argument &)
        {
            handler->print("Invalid input. Try again? [Yy/Nn] ");
            int option = getch();
            bool tryAgain = option == 'Y' || option == 'y';

            if (!tryAgain)
            {
                return new AuthenticatedInitPage(_user);
            }
            handler->clearLines(3);
        }
    }

    handler->clearScreen();

    handler->print("Please check the info provided");
    handler->print("");
    handler->print("First Name: " + firstName.get());
    handler->print("Last Name: " + lastName.get());
    handler->print("Email: " + email.get());
    handler->print("Phone Number: " + phoneNumber.get());
    handler->print("Password: " + password.get());
    handler->print("Role: " + role.get());
    handler->print("Is the info provided correct? [Yy/Nn]");

    int option = getch();
    bool isCorrect = option == 'Y' || option == 'y';

    if (!isCorrect)
    {
        return new UpdateUserPage(_user);
    }

    Participant newUser = Participant(registration, firstName, lastName, email, phoneNumber, password, role);

    result = handler->getServices()->getParticipantHandler()->update(newUser);

    if (result.status != SQLResult::SUCCESS)
    {
        handler->clearScreen();

        handler->print("Failed to update user.");
        handler->print(result.errorMessage);
        handler->print("");

        handler->print("Try again? [Yy/Nn]");

        int option = getch();
        bool tryAgain = option == 'Y' || option == 'y';

        if (!tryAgain)
        {
            return new AuthenticatedInitPage(_user);
        }

        return new UpdateUserPage(_user);
    }

    return new AuthenticatedInitPage(newUser);
}