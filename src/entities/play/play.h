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

    Play(std::string id, std::string name, PlayType type, std::string rating)
    {
        setId(id);
        setName(name);
        setType(type);
        setRating(rating);
    }

    Play() {}

    void setId(IdCode id)
    {
        _id = id;
    }

    void setId(std::string id)
    {
        _id = IdCode(id);
    }

    IdCode getId()
    {
        return _id;
    }

    void setName(Name name)
    {
        _name = name;
    }

    void setName(std::string name)
    {
        _name = Name(name);
    }

    Name getName()
    {
        return _name;
    }

    void setType(PlayType type)
    {
        _type = type;
    }

    void setType(std::string type)
    {
        _type = PlayType(type);
    }

    PlayType getType()
    {
        return _type;
    }

    void setRating(Rating rating)
    {
        _rating = rating;
    }

    void setRating(std::string rating)
    {
        _rating = Rating(rating);
    }

    Rating getRating()
    {
        return _rating;
    }
};

#endif