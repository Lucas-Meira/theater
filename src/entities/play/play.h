#ifndef PLAY_H
#define PLAY_H

#include "../../domains/domains.h"

class Play
{
private:
    IdCode _id;
    Name _name;
    PlayType _type;
    Rating _rating;

public:
    Play(IdCode id, Name name, PlayType type, Rating rating)
    {
        setId(id);
        setName(name);
        setType(type);
        setRating(rating);
    }

    Play() {}

    void
    setId(IdCode id)
    {
        _id = id;
    }

    IdCode getId()
    {
        return _id;
    }

    void setName(Name name)
    {
        _name = name;
    }

    Name getName()
    {
        return _name;
    }

    void setType(PlayType type)
    {
        _type = type;
    }

    PlayType getType()
    {
        return _type;
    }

    void setRating(Rating rating)
    {
        _rating = rating;
    }

    Rating getRating()
    {
        return _rating;
    }
};

#endif