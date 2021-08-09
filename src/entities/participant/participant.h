#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "../../domains/domains.h"

class Participant
{
private:
    Registration _registration;
    Name _firstName;
    Name _lastName;
    Email _email;
    PhoneNumber _phoneNumber;
    Password _password;
    Role _role;

public:
    Participant(const Registration &registration, const Name &firstName, const Name &lastName,
                const Email &email, const PhoneNumber &phoneNumber, const Password &password, const Role &role)
    {
        setRegistration(registration);
        setFirstName(firstName);
        setLastName(lastName);
        setEmail(email);
        setPhoneNumber(phoneNumber);
        setPassword(password);
        setRole(role);
    }

    Participant(const std::string &registration, const std::string &firstName, const std::string &lastName,
                const std::string &email, const std::string &phoneNumber, const std::string &password, const std::string &role)
    {
        setRegistration(registration);
        setFirstName(firstName);
        setLastName(lastName);
        setEmail(email);
        setPhoneNumber(phoneNumber);
        setPassword(password);
        setRole(role);
    }

    Participant() {}

    void setRegistration(Registration registration)
    {
        _registration = registration;
    }

    void setRegistration(std::string registration)
    {
        _registration = Registration(registration);
    }

    Registration getRegistration()
    {
        return _registration;
    }

    void setFirstName(Name name)
    {
        _firstName = name;
    }

    void setFirstName(std::string name)
    {
        _firstName = Name(name);
    }

    Name getFirstName()
    {
        return _firstName;
    }

    void setLastName(Name name)
    {
        _lastName = name;
    }

    void setLastName(std::string name)
    {
        _lastName = Name(name);
    }

    Name getLastName()
    {
        return _lastName;
    }

    Name getFullName()
    {
        return _firstName.get() + " " + _lastName.get();
    }

    void setEmail(Email email)
    {
        _email = email;
    }

    void setEmail(std::string email)
    {
        _email = Email(email);
    }

    Email getEmail()
    {
        return _email;
    }

    void setPhoneNumber(PhoneNumber phoneNumber)
    {
        _phoneNumber = phoneNumber;
    }

    void setPhoneNumber(std::string phoneNumber)
    {
        _phoneNumber = PhoneNumber(phoneNumber);
    }

    PhoneNumber getPhoneNumber()
    {
        return _phoneNumber;
    }

    void setPassword(Password password)
    {
        _password = password;
    }

    void setPassword(std::string password)
    {
        _password = Password(password);
    }

    Password getPassword()
    {
        return _password;
    }

    void setRole(Role role)
    {
        _role = role;
    }

    void setRole(std::string role)
    {
        _role = Role(role);
    }

    Role getRole()
    {
        return _role;
    }
};

#endif