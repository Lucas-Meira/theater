#ifndef SESSION_H
#define SESSION_H

#include "../../domains/domains.h"

///
/// This class stores all the information of the session of the play.
/// Types of information:
/// - Identification code
/// - Date of the session
/// - Time of the session
///

class Session
{
private:
    IdCode _id;
    Date _date;
    Time _time;

public:
    ///
    /// Calls all the methods set for the objects of the attributes of class Session, if its objects is already created.
    /// @param id
    /// @param date
    /// @param time
    ///

    Session(IdCode id, Date date, Time time)
    {
        setId(id);
        setDate(date);
        setTime(time);
    }

    ///
    /// Calls all the methods set for the objects of the attributes of class Session.
    /// @param id
    /// @param date
    /// @param time
    ///

    Session(std::string id, std::string date, std::string time)
    {
        setId(id);
        setDate(date);
        setTime(time);
    }

    ///
    /// Creates an instance of the classSession.
    ///

    Session() {}

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
    /// Stores an already created object of class Date.
    /// @param date
    ///

    void setDate(Date date)
    {
        _date = date;
    }

    ///
    /// Creates and stores the object of the class Date.
    /// @param date
    ///

    void setDate(std::string date)
    {
        _date = Date(date);
    }

    ///
    /// Returns the stored object of the class Date.
    /// @return _date
    ///

    Date getDate()
    {
        return _date;
    }

    ///
    /// Stores an already created object of class Time.
    /// @param time
    ///

    void setTime(Time time)
    {
        _time = time;
    }

    ///
    /// Creates and stores the object of the class Time.
    /// @param time
    ///

    void setTime(std::string time)
    {
        _time = Time(time);
    }

    ///
    /// Returns the stored object of the class Time.
    /// @return _time
    ///

    Time getTime()
    {
        return _time;
    }
};

#endif