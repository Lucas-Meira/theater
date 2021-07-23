#ifndef ENTITIES_H
#define ENTITIES_H

#include "domains.h"

class Participan
{
private:
    Immatriculation immatriculation;
    Name name;
    Name lastName;
    Email emailAddress;
    PhoneNumber phoneNumber;
    Password password;
    Role role;
};

class Play
{
private:
    IdCode id;
    Name name;
    PlayType type;
    Rating rating;
};

class Session
{
private:
    IdCode id;
    Date date;
    Time time;
};

class Room
{
private:
    IdCode id;
    Name name;
    Capacity capacity;
};

#endif