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

    Play(const IdCode &id, const Name &name, const PlayType &type, const Rating &rating)
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

    Play(const std::string &id, const std::string &name, const PlayType &type, const std::string &rating)
    {
        setId(id);
        setName(name);
        setType(type);
        setRating(rating);
    }

    ///
    /// Creates an instance of the classPlay.
    ///

    Play() {}

    ///
    /// Stores an already created object of class IdCode.
    /// @param id
    ///

    void setId(const IdCode &id)
    {
        _id = id;
    }

    ///
    /// Creates and stores the object of the class IdCode.
    /// @param id
    ///

    void setId(const std::string &id)
    {
        _id = IdCode(id);
    }

    ///
    /// Returns the stored object of the class IdCode.
    /// @return _id
    ///

    IdCode getId() const
    {
        return _id;
    }

    ///
    /// Stores an already created object of class Name.
    /// @param name
    ///

    void setName(const Name &name)
    {
        _name = name;
    }

    ///
    /// Creates and stores the object of the class Name.
    /// @param name
    ///

    void setName(const std::string &name)
    {
        _name = Name(name);
    }

    ///
    /// Returns the stored object of the class Name.
    /// @return _name
    ///

    Name getName() const
    {
        return _name;
    }

    ///
    /// Stores an already created object of class PlayType.
    /// @param type
    ///

    void setType(const PlayType &type)
    {
        _type = type;
    }

    ///
    /// Creates and stores the object of the class PlayType.
    /// @param type
    ///

    void setType(const std::string &type)
    {
        _type = PlayType(type);
    }

    ///
    /// Returns the stored object of the class PlayType.
    /// @return _type
    ///

    PlayType getType() const
    {
        return _type;
    }

    ///
    /// Stores an already created object of class Rating.
    /// @param rating
    ///

    void setRating(const Rating &rating)
    {
        _rating = rating;
    }

    ///
    /// Creates and stores the object of the class Rating.
    /// @param rating
    ///

    void setRating(const std::string &rating)
    {
        _rating = Rating(rating);
    }

    ///
    /// Returns the stored object of the class Rating.
    /// @return _rating
    ///

    Rating getRating() const
    {
        return _rating;
    }
};

#endif