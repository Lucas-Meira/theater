#ifndef ENTITIES_H
#define ENTITIES_H

#include "domains.h"

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
    inline Immatriculation setImmatriculation(Immatriculation immatriculation)
    {
        _immatriculation = immatriculation;
    }

    inline Immatriculation getImmatriculation()
    {
        return _immatriculation;
    }

    inline Name setFirstName(Name name)
    {
        _firstName = name;
    }

    inline Name getFirstName()
    {
        return _firstName;
    }

    inline Name setLastName(Name name)
    {
        _lastName = name;
    }

    inline Name getLastName()
    {
        return _lastName;
    }

    inline Name getFullName()
    {
        return _firstName.get() + " " + _lastName.get();
    }

    inline Email setEmail(Email email)
    {
        _email = email;
    }

    inline Email getEmail()
    {
        return _email;
    }

    inline PhoneNumber setPhoneNumber(PhoneNumber phoneNumber)
    {
        _phoneNumber = phoneNumber;
    }

    inline PhoneNumber getPhoneNumber()
    {
        return _phoneNumber;
    }

    inline Password setPassword(Password password)
    {
        _password = password;
    }

    inline Password getPassword()
    {
        return _password;
    }

    inline Role setRole(Role role)
    {
        _role = role;
    }

    inline Role getRole()
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
    inline IdCode setId(IdCode id)
    {
        _id = id;
    }

    inline IdCode getId()
    {
        return _id;
    }

    inline Name setName(Name name)
    {
        _name = name;
    }

    inline Name getName()
    {
        return _name;
    }

    inline PlayType setType(PlayType type)
    {
        _type = type;
    }

    inline PlayType getType()
    {
        return _type;
    }

    inline Rating setRating(Rating rating)
    {
        _rating = rating;
    }

    inline Rating getRating()
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
    inline IdCode setId(IdCode id)
    {
        _id = id;
    }

    inline IdCode getId()
    {
        return _id;
    }

    inline Date setDate(Date date)
    {
        _date = date;
    }

    inline Date getDate()
    {
        return _date;
    }

    inline Time setTime(Time time)
    {
        _time = time;
    }

    inline Time getTime()
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
    inline IdCode setId(IdCode id)
    {
        _id = id;
    }

    inline IdCode getId()
    {
        return _id;
    }

    inline Name setName(Name name)
    {
        _name = name;
    }

    inline Name getName()
    {
        return _name;
    }

    inline Capacity setCapacity(Capacity capacity)
    {
        _capacity = capacity;
    }

    inline Capacity getCapacity()
    {
        return _capacity;
    }
};

#endif
