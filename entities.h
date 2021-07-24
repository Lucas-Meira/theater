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
    Immatriculation setImmatriculation(Immatriculation);
    Immatriculation getImmatriculation();

    Name setFirstName(Name name);
    Name getFirstName();

    Name setLastName(Name name);
    Name getLastName();

    Name getFullName();

    Email setEmail(Email email);
    Email getEmail();

    PhoneNumber setPhoneNumber(PhoneNumber phoneNumber);
    PhoneNumber getPhoneNumber();

    Password setPassword(Password password);
    Password getPassword();

    Role setRole(Role role);
    Role getRole();
};

class Play
{
private:
    IdCode _id;
    Name _name;
    PlayType _type;
    Rating _rating;

public:
    IdCode setId(IdCode id);
    IdCode getId();

    Name setName(Name name);
    Name getName();

    PlayType setType(PlayType playType);
    PlayType getType();

    Rating setRating(Rating rating);
    Rating getRating();
};

class Session
{
private:
    IdCode _id;
    Date _date;
    Time _time;

public:
    IdCode setId(IdCode id);
    IdCode getId();

    Date setDate(Date date);
    Date getDate();

    Time setTime(Time time);
    Time getTime();
};

class Room
{
private:
    IdCode _id;
    Name _name;
    Capacity _capacity;

public:
    IdCode setId(IdCode id);
    IdCode getId();

    Name setName(Name name);
    Name getName();

    Capacity setCapacity(Capacity capacity);
    Capacity getCapacity();
};

#endif
