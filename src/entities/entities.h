#ifndef ENTITIES_H
#define ENTITIES_H

#include "domains/domains.h"

class Participant
{
private:
    Immatriculation _immatriculation;
    Name _firstName;
    Name _lastName;
    Email _email;
    PhoneNumber _phoneNumber;
    Password _password;
    Role _role;

public:
    Immatriculation setImmatriculation(Immatriculation immatriculation)
    {
        _immatriculation = immatriculation;
    }

    Immatriculation getImmatriculation()
    {
        return _immatriculation;
    }

    Name setFirstName(Name name)
    {
        _firstName = name;
    }

    Name getFirstName()
    {
        return _firstName;
    }

    Name setLastName(Name name)
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

    Email setEmail(Email email)
    {
        _email = email;
    }

    Email getEmail()
    {
        return _email;
    }

    PhoneNumber setPhoneNumber(PhoneNumber phoneNumber)
    {
        _phoneNumber = phoneNumber;
    }

    PhoneNumber getPhoneNumber()
    {
        return _phoneNumber;
    }

    Password setPassword(Password password)
    {
        _password = password;
    }

    Password getPassword()
    {
        return _password;
    }

    Role setRole(Role role)
    {
        _role = role;
    }

    Role getRole()
    {
        return _role;
    }
};

class Play
{
private:
    IdCode _id;
    Name _name;
    PlayType _type;
    Rating _rating;

public:
    IdCode setId(IdCode id)
    {
        _id = id;
    }

    IdCode getId()
    {
        return _id;
    }

    Name setName(Name name)
    {
        _name = name;
    }

    Name getName()
    {
        return _name;
    }

    PlayType setType(PlayType type)
    {
        _type = type;
    }

    PlayType getType()
    {
        return _type;
    }

    Rating setRating(Rating rating)
    {
        _rating = rating;
    }

    Rating getRating()
    {
        return _rating;
    }
};

class Session
{
private:
    IdCode _id;
    Date _date;
    Time _time;

public:
    IdCode setId(IdCode id)
    {
        _id = id;
    }

    IdCode getId()
    {
        return _id;
    }

    Date setDate(Date date)
    {
        _date = date;
    }

    Date getDate()
    {
        return _date;
    }

    Time setTime(Time time)
    {
        _time = time;
    }

    Time getTime()
    {
        return _time;
    }
};

class Room
{
private:
    IdCode _id;
    Name _name;
    Capacity _capacity;

public:
    IdCode setId(IdCode id)
    {
        _id = id;
    }

    IdCode getId()
    {
        return _id;
    }

    Name setName(Name name)
    {
        _name = name;
    }

    Name getName()
    {
        return _name;
    }

    Capacity setCapacity(Capacity capacity)
    {
        _capacity = capacity;
    }

    Capacity getCapacity()
    {
        return _capacity;
    }
};

#endif
