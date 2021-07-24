#ifndef ENTITIES_H
#define ENTITIES_H

#include "domains.h"

class Participant
{
private:
    Immatriculation _immatriculation;
    Name _name;
    Name _lastName;
    Email _emailAddress;
    PhoneNumber _phoneNumber;
    Password _password;
    Role _role;
};

class Play
{
private:
    IdCode _id;
    Name _name;
    PlayType _type;
    Rating _rating;
};

class Session
{
private:
    IdCode _id;
    Date _date;
    Time _time;
};

class Room
{
private:
    IdCode _id;
    Name _name;
    Capacity _capacity;
};

#endif
