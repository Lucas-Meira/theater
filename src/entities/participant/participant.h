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
    void setRegistration(Registration registration)
    {
        _registration = registration;
    }

    Registration getRegistration()
    {
        return _registration;
    }

    void setFirstName(Name name)
    {
        _firstName = name;
    }

    Name getFirstName()
    {
        return _firstName;
    }

    void setLastName(Name name)
    {
        _lastName = name;
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

    Email getEmail()
    {
        return _email;
    }

    void setPhoneNumber(PhoneNumber phoneNumber)
    {
        _phoneNumber = phoneNumber;
    }

    PhoneNumber getPhoneNumber()
    {
        return _phoneNumber;
    }

    void setPassword(Password password)
    {
        _password = password;
    }

    Password getPassword()
    {
        return _password;
    }

    void setRole(Role role)
    {
        _role = role;
    }

    Role getRole()
    {
        return _role;
    }
};

#endif