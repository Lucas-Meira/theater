#ifndef PLAY_H
#define PLAY_H

#include "../../domains/domains.h"

///
/// This class stores all the information of the play in the theater.
/// Types of information:
/// - Identification code
/// - Name
/// - Type of the play
/// - Age rating
///

class Play
{
private:
    IdCode _id;
    Name _name;
    PlayType _type;
    Rating _rating;

public:
    ///
    /// Calls all the methods set for the objects of the attributes of class Play, if its objects is already created.
    /// @param id
    /// @param name
    /// @param type
    /// @param rating
    ///

    Play(IdCode id, Name name, PlayType type, Rating rating)
    {
        setId(id);
        setName(name);
        setType(type);
        setRating(rating);
    }

    ///
    /// Calls all the methods set for the objects of the attributes of class Play.
    /// @param id
    /// @param name
    /// @param type
    /// @param rating
    ///

    Play(std::string id, std::string name, PlayType type, std::string rating)
    {
        setId(id);
        setName(name);
        setType(type);
        setRating(rating);
    }

    ///
    /// Creates an instance of the class Play.
    ///

    Play() {}

    ///
    /// Stores an already created object of class IdCode.
    /// @param id
    ///

    void setId(IdCode id)
    {
        _id = id;
    }

    ///
    /// Creates and stores the object of the class IdCode.
    /// @param id
    ///

    void setId(std::string id)
    {
        _id = IdCode(id);
    }

    ///
    /// Returns the stored object of the class IdCode.
    /// @return _id
    ///

    IdCode getId()
    {
        return _id;
    }

    ///
    /// Stores an already created object of class Name.
    /// @param name
    ///

    void setName(Name name)
    {
        _name = name;
    }

    ///
    /// Creates and stores the object of the class Name.
    /// @param name
    ///

    void setName(std::string name)
    {
        _name = Name(name);
    }

    ///
    /// Returns the stored object of the class Name.
    /// @return _name
    ///

    Name getName()
    {
        return _name;
    }

    ///
    /// Stores an already created object of class PlayType.
    /// @param type
    ///

    void setType(PlayType type)
    {
        _type = type;
    }

    ///
    /// Creates and stores the object of the class PlayType.
    /// @param type
    ///

    void setType(std::string type)
    {
        _type = PlayType(type);
    }

    ///
    /// Returns the stored object of the class PlayType.
    /// @return _type
    ///

    PlayType getType()
    {
        return _type;
    }

    ///
    /// Stores an already created object of class Rating.
    /// @param rating
    ///

    void setRating(Rating rating)
    {
        _rating = rating;
    }

    ///
    /// Creates and stores the object of the class Rating.
    /// @param rating
    ///

    void setRating(std::string rating)
    {
        _rating = Rating(rating);
    }

    ///
    /// Returns the stored object of the class Rating.
    /// @return _rating
    ///

    Rating getRating()
    {
        return _rating;
    }
};

#endif